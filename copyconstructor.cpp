#include <iostream>
using namespace std;

class Wall {
  private:
    double length;
    double height;

  public:

    Wall(double len, double hgt)
      : length{len}
      , height{hgt} {
    }

    Wall(const Wall& obj)
      : length{obj.length}
      , height{obj.height} {
    }

    double calculateArea() {
      return length * height;
    }
};

int main() {
  Wall wall1(12.5, 5.4);

  Wall wall2 = wall1;

  cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
  cout << "Area of Wall 2: " << wall2.calculateArea() << endl;

  return 0;
}
