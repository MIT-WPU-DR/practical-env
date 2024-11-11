#include<iostream>
#include<string.h>

using namespace std;
class student
{
	public:
	string name;
	int rollno,Class, division;
	char dob[10]; 
	int adharno; 
	string bloodgroup; 
	int contactno; 
	string address;
	int telephoneno;

student()
{
	name="ambika";
	rollno=42;
	Class=2;
	division=20;
	adharno=123;
	bloodgroup="a";
	contactno=982;
	address="pune";
	telephoneno=456;
	strcpy(dob,"abc");
}
	student(string n,int r,int d,int c,char db[],int an, string bg,int 
	cn,string ad,int tn)
{
	name=n;
	rollno=r;
	division=d;
	Class=c;
	strcpy(dob,db);
	adharno=an;
	bloodgroup=bg;
	contactno=cn;
	address=ad;
	telephoneno=tn;
}
student(student &p)
{
	rollno=p.rollno;
	Class=p.Class;
	division=p.division;
	strcpy(dob,p.dob);
	adharno=p.adharno;
	bloodgroup=p.bloodgroup;
	contactno=p.contactno;
	address=p.address;
	telephoneno=p.telephoneno;
}
void putdata()
{
	cout<<"Student name is "<<name<<endl;
	cout<<"Student rollno is "<<rollno<<endl;
	cout<<"Student Class is "<<Class<<endl;
	cout<<"Student division is "<<division<<endl;
	cout<<"Student dob is "<<dob<<endl;
	cout<<"Student adharno is "<<adharno<<endl;
	cout<<"Student bloodgroup is "<<bloodgroup<<endl;
	cout<<"Student contactno is "<<contactno<<endl;
	cout<<"Student address is "<<address<<endl;
	cout<<"Student telephoneno is "<<telephoneno<<endl;
}
~student()
{
    cout<<"Destructor is called";
}
};
int main()
{
	 int i;
	student a;
	cout<<"Default Constructor is called";
	a.putdata();
	int n;
	cout<<"Parametrized Constructor is called";
	student p("aaa",1,1,1,"asda",1,"as",1,"asd",1);
	p.putdata();
	student cp(p);
	cout<<"Copy Constructor is called";
	cp.putdata();
	return 0;
}
