// Develop an object oriented program in C++  to create a database of student information systems containing the following information: Name, Roll Number, Class, division, DOB, Aadhar no, Blood Group, Contact address, telephne number,etc.
// Count the number of students in the database using a variable count which is a member of the student class. Also display the total number of students using a static function


# include <iostream>
# include <string>

using namespace std;

class student
{
	public:
	string name;
	int rollno, Class, division;
	char dob[10];
	private:
	int aadharno, telephoneno;
	string blood_group, contact_address;
	static int count;
	void displayInfo() const{
		cout << "Name: " << name << endl;
		
};

int Student::cout = 0;

