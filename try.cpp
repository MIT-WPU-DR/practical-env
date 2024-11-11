#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>
#include <memory>
#include <stdexcept>

using namespace ftxui;

// Forward declarations
class GameObject;
class Character;
class Player;
class GameScreen;

// Custom exception class to demonstrate exception handling
class GameException : public std::runtime_error {
public:
    GameException(const std::string& message) : std::runtime_error(message) {}
};

// Template class to demonstrate templates - can be used for various game stats
template<typename T>
class Stat {
private:
    T current;
    T maximum;
public:
    Stat(T initial = T(), T max = T()) : current(initial), maximum(max) {}
    
    T getCurrent() const { return current; }
    T getMaximum() const { return maximum; }
    
    void modify(T amount) {
        current = std::min(maximum, std::max(T(), current + amount));
    }
};

// Base class for all game objects - demonstrates inheritance
class GameObject {
protected:
    std::string name;
    std::string description;
    int x, y;  // Position

public:
    // Default constructor
    GameObject() : name("Unknown"), description(""), x(0), y(0) {}
    
    // Parameterized constructor
    GameObject(const std::string& n, const std::string& desc, int posX = 0, int posY = 0)
        : name(n), description(desc), x(posX), y(posY) {}
    
    // Copy constructor
    GameObject(const GameObject& other)
        : name(other.name), description(other.description), x(other.x), y(other.y) {}
    
    // Virtual destructor for proper cleanup in inheritance hierarchy
    virtual ~GameObject() = default;
    
    // Pure virtual function to demonstrate polymorphism
    virtual std::string render() const = 0;
    
    // Getters/Setters
    virtual void move(int newX, int newY) {
        x = newX;
        y = newY;
    }
    
    int getX() const { return x; }
    int getY() const { return y; }
    std::string getName() const { return name; }
};

// Character class inherits from GameObject
class Character : public GameObject {
protected:
    Stat<int> health;
    Stat<int> energy;

public:
    Character(const std::string& n, const std::string& desc, int maxHealth = 100)
        : GameObject(n, desc), health(maxHealth, maxHealth), energy(100, 100) {}
    
    virtual std::string render() const override {
        return "@";  // Basic character representation
    }
    
    virtual void takeDamage(int amount) {
        health.modify(-amount);
        if (health.getCurrent() <= 0) {
            throw GameException(getName() + " has been defeated!");
        }
    }
};

// Player class demonstrates further inheritance
class Player : public Character {
private:
    std::vector<std::string> inventory;  // Demonstrates STL vector usage

public:
    Player(const std::string& name = "Alex")
        : Character(name, "A maintenance worker who discovered a crucial secret", 100) {}
    
    void addItem(const std::string& item) {
        inventory.push_back(item);
    }
    
    const std::vector<std::string>& getInventory() const {
        return inventory;
    }
    
    std::string render() const override {
        return "☺";  // Player character representation
    }
};

// GameScreen class to manage the FTXUI interface
class GameScreen {
private:
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    Element gameTitle;

public:
    GameScreen() : player(std::make_shared<Player>()) {
        // ASCII art title
        gameTitle = vbox({
            text("╔═══════════════════════════════════════════╗"),
            text("║   SPACE DYSTOPIA: THE LAST FRONTIER       ║"),
            text("║                                           ║"),
            text("║        A Journey Beyond the Stars         ║"),
            text("╚═══════════════════════════════════════════╝")
        });
    }

    // Main render function for the game screen
    Element render() {
        // Game area
        auto gameArea = window(
            text("Europa Station") | hcenter,
            vbox({
                // Game content will go here
                text("Use arrow keys to move, 'q' to quit")
            })
        );

        // Status panel
        auto statusPanel = window(
            text("Status") | hcenter,
            vbox({
                text("Health: " + std::to_string(100)),
                text("Energy: " + std::to_string(100)),
                text("Location: Europa")
            })
        );

        // Command panel
        auto commandPanel = window(
            text("Commands") | hcenter,
            vbox({
                text("↑↓←→ : Move"),
                text("I : Inventory"),
                text("T : Talk"),
                text("Q : Quit")
            })
        );

        // Combine all elements
        return vbox({
            gameTitle,
            hbox({
                gameArea | flex,
                vbox({
                    statusPanel,
                    commandPanel
                })
            })
        });
    }
};
