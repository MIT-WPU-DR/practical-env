#include <iostream>
#include <string>

using namespace std;
class Student
{
	string name;
	int marks;
	public:
	void setName()
	{
		cin >> name;
	}
	void setMarks()
	{
		cin >> marks;
	}

	void displayInfo()
	{
		cout << "Name: " << name << endl;
		cout << "Marks: " << marks << endl << endl;
	}
};
	
int main()
{
	Student st[5];
	for ( int i = 0; i<5; i++)
	{
		cout << "Student" << i+1 << endl;
		cout << "Enter name" << endl;
		st[i].setName();
		cout << "Enter marks" << endl;
		st[i].setMarks();
	}
	for (int i = 0 ; i<5; i++)
	{
		cout << "Student" << i+1 << endl;
		st[i].displayInfo();
	}
	return 0;
}
