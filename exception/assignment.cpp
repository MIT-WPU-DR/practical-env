#include <iostream>
#include <string>
#include <stdexcept>

class Hotel {
private:
    std::string cust_name;
    int cust_id;
    int age;
    int income;
    std::string city;
    std::string room_type;

public:
    Hotel() : cust_id(0), age(0), income(0) {}

    void accept() {
        std::cout << "Enter customer name: ";
        std::cin >> cust_name;
        std::cout << "Enter customer ID: ";
        std::cin >> cust_id;
        std::cout << "Enter customer age: ";
        std::cin >> age;
        std::cout << "Enter customer income: ";
        std::cin >> income;
        std::cout << "Enter city (Pune or Mumbai): ";
        std::cin >> city;
        std::cout << "Enter room type (deluxe or super deluxe): ";
        std::cin >> room_type;
    }

    void display() {
        std::cout << "\nCustomer Information:" << std::endl;
        std::cout << "Name: " << cust_name << std::endl;
        std::cout << "ID: " << cust_id << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Income: " << income << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Room Type: " << room_type << std::endl;
    }

    void validateBooking() {
        if (age < 18 || age > 55) {
            throw std::runtime_error("Age must be between 18 and 55");
        }
        if (income < 50000 || income > 100000) {
            throw std::runtime_error("Income must be between 50000 and 100000");
        }
        if (city != "Pune" && city != "Mumbai") {
            throw std::runtime_error("City must be Pune or Mumbai");
        }
        if (room_type != "deluxe" && room_type != "super deluxe") {
            throw std::runtime_error("Room type must be deluxe or super deluxe");
        }
    }

};

int main() {
    Hotel hotel;

    hotel.accept();

    try {
        hotel.validateBooking();
        std::cout << "\nBooking successful!" << std::endl;
        hotel.display();
    } catch (const std::exception& e) {
        std::cout << "\nError: " << e.what() << std::endl;
    }

    return 0;
}
