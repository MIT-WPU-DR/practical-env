#include <iostream>
using namespace std;

class AgeException {};
class IncomeException {};
class CityException {};
class RoomTypeException {};

class Hotel {
private:
    string cust_name;
    int cust_id;
    int age;
    int income;
    string city;
    string room_type;

public:
    Hotel() : cust_id(0), age(0), income(0) {}

    void accept() {
        cout << "Enter customer name: ";
        cin >> cust_name;
        cout << "Enter customer ID: ";
        cin >> cust_id;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter income: ";
        cin >> income;
        cout << "Enter city: ";
        cin >> city;
        cout << "Enter room type: ";
        cin >> room_type;
    }

    void display() {
        cout << "\nCustomer Details:" << endl;
        cout << "Name: " << cust_name << endl;
        cout << "ID: " << cust_id << endl;
        cout << "Age: " << age << endl;
        cout << "Income: " << income << endl;
        cout << "City: " << city << endl;
        cout << "Room Type: " << room_type << endl;
    }

    int getage() { return age; }
    int getincome() { return income; }
    string getcity() { return city; }
    string getroomtype() { return room_type; }

    void validateBooking() {
        if (age < 18 || age > 55) throw AgeException();
        if (income < 50000 || income > 100000) throw IncomeException();
        if (city != "Pune" && city != "Mumbai") throw CityException();
        if (room_type != "deluxe" && room_type != "super deluxe") throw RoomTypeException();
    }
};

int main() {
    Hotel h;
    h.accept();

    try {
        h.validateBooking();
        h.display();
    }
    catch (AgeException) {
        cout << "Error: Age must be between 18 and 55." << endl;
    }
    catch (IncomeException) {
        cout << "Error: Income must be between 50000 and 100000." << endl;
    }
    catch (CityException) {
        cout << "Error: City must be either Pune or Mumbai." << endl;
    }
    catch (RoomTypeException) {
        cout << "Error: Room type must be either deluxe or super deluxe." << endl;
    }

    return 0;
}
