#include <ncurses.h>
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

// Forward declaration
class GameObject;

// Template for game messages
template<typename T>
void displayMessage(const T& msg, int y, int x) {
    mvprintw(y, x, std::to_string(msg).c_str());
}

template<>
void displayMessage<std::string>(const std::string& msg, int y, int x) {
    mvprintw(y, x, msg.c_str());
}

// Base class for all game objects
class GameObject {
protected:
    int x, y;
    char symbol;

public:
    // Default constructor
    GameObject() : x(0), y(0), symbol('?') {}
    
    // Parameterized constructor
    GameObject(int posX, int posY, char sym) : x(posX), y(posY), symbol(sym) {}
    
    // Copy constructor
    GameObject(const GameObject& other) : x(other.x), y(other.y), symbol(other.symbol) {}
    
    virtual ~GameObject() {} // Virtual destructor
    
    // Pure virtual function for polymorphism
    virtual void display() = 0;
    
    int getX() const { return x; }
    int getY() const { return y; }
};

// Player class demonstrating inheritance
class Player : public GameObject {
private:
    std::vector<std::string> inventory;
    int health;

public:
    Player(int startX, int startY) : GameObject(startX, startY, '@'), health(100) {}

    void display() override {
        mvaddch(y, x, symbol);
    }

    void move(int dx, int dy, int maxY, int maxX) {
        try {
            int newX = x + dx;
            int newY = y + dy;
            
            if (newX >= 0 && newX < maxX && newY >= 0 && newY < maxY) {
                x = newX;
                y = newY;
            } else {
                throw std::runtime_error("Cannot move outside bounds!");
            }
        } catch (const std::exception& e) {
            // Silently handle boundary exception
        }
    }

    // Template method for health modification
    template<typename T>
    void modifyHealth(T amount) {
        health += static_cast<int>(amount);
        if (health > 100) health = 100;
        if (health < 0) health = 0;
    }

    int getHealth() const { return health; }
};

// Item class for collectibles
class Item : public GameObject {
private:
    std::string name;

public:
    Item(int posX, int posY, const std::string& itemName) 
        : GameObject(posX, posY, '*'), name(itemName) {}

    void display() override {
        mvaddch(y, x, symbol);
    }

    std::string getName() const { return name; }
};

// Game manager class
class GameManager {
private:
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Item>> items;
    int maxY, maxX;
    bool gameRunning;

    void displayTitleScreen() {
        clear();
        mvprintw(5, maxX/2 - 15, "Space Dystopia: The Last Frontier");
        mvprintw(7, maxX/2 - 10, "Year 2350");
        mvprintw(9, maxX/2 - 20, "Use arrow keys to move, 'q' to quit");
        mvprintw(11, maxX/2 - 15, "Press any key to start...");
        refresh();
        getch();
    }

    void spawnItems() {
        // Spawn some random items
        for (int i = 0; i < 5; i++) {
            int randX = rand() % (maxX - 2) + 1;
            int randY = rand() % (maxY - 2) + 1;
            items.push_back(std::make_unique<Item>(randX, randY, "Data Chip"));
        }
    }

    void checkCollisions() {
        for (auto it = items.begin(); it != items.end(); ) {
            if ((*it)->getX() == player->getX() && (*it)->getY() == player->getY()) {
                displayMessage("Found a " + (*it)->getName() + "!", maxY-1, 0);
                it = items.erase(it);
                player->modifyHealth(10);  // Heal player when collecting items
            } else {
                ++it;
            }
        }
    }

public:
    GameManager() : gameRunning(true) {
        srand(time(nullptr));
        
        // Initialize ncurses
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
        
        // Get terminal size
        getmaxyx(stdscr, maxY, maxX);
        
        // Create player in center of screen
        player = std::make_unique<Player>(maxX/2, maxY/2);
        
        spawnItems();
    }

    ~GameManager() {
        endwin();
    }

    void run() {
        displayTitleScreen();

        while (gameRunning) {
            // Clear screen
            clear();

            // Display border
            for (int i = 0; i < maxX; i++) {
                mvaddch(0, i, '-');
                mvaddch(maxY-1, i, '-');
            }
            for (int i = 0; i < maxY; i++) {
                mvaddch(i, 0, '|');
                mvaddch(i, maxX-1, '|');
            }

            // Display status
            displayMessage("Health: " + std::to_string(player->getHealth()), 0, 1);

            // Display all game objects
            player->display();
            for (const auto& item : items) {
                item->display();
            }

            // Process input
            int ch = getch();
            switch (ch) {
                case KEY_UP:    player->move(0, -1, maxY, maxX); break;
                case KEY_DOWN:  player->move(0, 1, maxY, maxX); break;
                case KEY_LEFT:  player->move(-1, 0, maxY, maxX); break;
                case KEY_RIGHT: player->move(1, 0, maxY, maxX); break;
                case 'q':     gameRunning = false; break;
            }

            checkCollisions();
            refresh();
        }
    }
};

int main() {
    try {
        GameManager game;
        game.run();
    } catch (const std::exception& e) {
        endwin();
        return 1;
    }
    return 0;
}
