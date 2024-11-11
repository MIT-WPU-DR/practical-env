
#include<iostream>
using namespace std;

class student
{
	public: 
	string name;
	int rollno,Class, division;
	string dob; 
	int adharno; 
	string bloodgroup; 
	int contactno; 
	string address;
	int telephoneno;
	static int count;

	static void total_students()
	{
	   cout<<"Total student count "<<count << endl; 
	}

	student()
	{
		name="Ayush";
		rollno=54;
		Class=2;
		division=2;
		adharno=98467812;
		bloodgroup="B+";
		contactno=7588742;
		address="Pune";
		telephoneno=94266061;
		dob = "07.12.2005";
		count=count+1; 
	}

	void putdata()
	{
		cout<<"Student Name is "<<name<<endl;
		cout<<"Student Roll No. is "<<rollno<<endl;
		cout<<"Student Class is "<<Class<<endl;
		cout<<"Student Division is "<<division<<endl;
		cout<<"Student Date of Birth is "<<dob<<endl;
		cout<<"Student Aadhar No. is "<<adharno<<endl;
		cout<<"Student Blood Group is "<<bloodgroup<<endl;
		cout<<"Student Contact No. is "<<contactno<<endl;
		cout<<"Student Address is "<<address<<endl;
		cout<<"Student Telephone No. is "<<telephoneno<<endl;
	}

};

int student::count;

int main()
{
	int i;
	student a, b;
	a.putdata();

	cout << "Putting 2 students (a & b)" << endl;
	student::total_students();
	return 0;
}
