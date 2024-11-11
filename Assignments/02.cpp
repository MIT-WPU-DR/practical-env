#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char name[50];
    int rollNumber;
    char className[20];
    char division;
    char dateOfBirth[11];
    char aadharNumber[13];
    char bloodGroup[4];
    char contactAddress[100];
    long telephoneNumber;

public:
    // Default constructor
    Student() {
        strcpy(name, "Ayush");
        rollNumber = 102045;
        strcpy(className, "OOP");
        division = 'B';
        strcpy(dateOfBirth, "07-12-2005");
        strcpy(aadharNumber, "9485 3834 8459");
        strcpy(bloodGroup, "B+");
        strcpy(contactAddress, "Pune");
        telephoneNumber = 9920485937;
    }

    // Parameterized constructor
    Student(const char* n, int roll, const char* class_name, char div, const char* dob,
            const char* aadhar, const char* blood, const char* address, long phone) {
        strcpy(name, n);
        rollNumber = roll;
        strcpy(className, class_name);
        division = div;
        strcpy(dateOfBirth, dob);
        strcpy(aadharNumber, aadhar);
        strcpy(bloodGroup, blood);
        strcpy(contactAddress, address);
        telephoneNumber = phone;
    }

    // Copy constructor
    Student(const Student& other) {
        strcpy(name, other.name);
        rollNumber = other.rollNumber;
        strcpy(className, other.className);
        division = other.division;
        strcpy(dateOfBirth, other.dateOfBirth);
        strcpy(aadharNumber, other.aadharNumber);
        strcpy(bloodGroup, other.bloodGroup);
        strcpy(contactAddress, other.contactAddress);
        telephoneNumber = other.telephoneNumber;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Aadhar Number: " << aadharNumber << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "------------------------" << endl;
        cout << endl;
    }
};

int main() {
    // Using default constructor
    Student student1;
    cout << "Student 1 (Default Constructor):" << endl;
    student1.display();

    // Using parameterized constructor
    Student student2("Rohan", 1038492390, "SYAIDS", 'A', "20-08-2005", "9850 4850 9490", "O+", "Mumbai", 9485038596);
    cout << "Student 2 (Parameterized Constructor):" << endl;
    student2.display();

    // Using copy constructor
    Student student3 = student2;
    cout << "Student 3 (Copy Constructor):" << endl;
    student3.display();

    return 0;
}
