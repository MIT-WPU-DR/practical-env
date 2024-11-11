#include <iostream>
using namespace std;

class Employee {
protected:
    char Ename[50];
    int EmpID;

public:
    Employee() : EmpID(0) {
        Ename[0] = '\0';
    }

    Employee(const char* name, int id) : EmpID(id) {
        int i;
        for (i = 0; name[i] != '\0' && i < 49; i++) {
            Ename[i] = name[i];
        }
        Ename[i] = '\0';
    }

    virtual void accept() {
        cout << "Enter Employee Name: ";
        cin >> Ename;
        cout << "Enter Employee ID: ";
        cin >> EmpID;
    }

    virtual void display() {
        cout << "Employee Name: " << Ename << endl;
        cout << "Employee ID: " << EmpID << endl;
    }

    virtual double earnings() = 0;
};

class SalariedEmployee : public Employee {
private:
    double weeklySalary;

public:
    SalariedEmployee() : weeklySalary(0) {}

    SalariedEmployee(const char* name, int id, double salary)
        : Employee(name, id), weeklySalary(salary) {}

    void accept() override {
        Employee::accept();
        cout << "Enter Weekly Salary: ";
        cin >> weeklySalary;
    }

    void display() override {
        Employee::display();
        cout << "Weekly Salary: $" << weeklySalary << endl;
    }

    double earnings() override {
        return weeklySalary;
    }
};

class HourlyEmployee : public Employee {
private:
    double wage;
    double hours;
    double hourlySalary;

public:
    HourlyEmployee() : wage(0), hours(0), hourlySalary(0) {}

    HourlyEmployee(const char* name, int id, double w, double h)
        : Employee(name, id), wage(w), hours(h), hourlySalary(0) {}

    void accept() override {
        Employee::accept();
        cout << "Enter Hourly Wage: ";
        cin >> wage;
        cout << "Enter Hours Worked: ";
        cin >> hours;
    }

    void display() override {
        Employee::display();
        cout << "Hourly Wage: $" << wage << endl;
        cout << "Hours Worked: " << hours << endl;
    }

    double earnings() override {
        if (hours < 40) {
            hourlySalary = hours * wage;
        } else {
            hourlySalary = 40 * wage + ((hours - 40) * wage) * 1.5;
        }
        return hourlySalary;
    }
};

class CommissionEmployee : public Employee {
private:
    double grossSales;
    double commissionRate;
    double commissionSalary;

public:
    CommissionEmployee() : grossSales(0), commissionRate(0), commissionSalary(0) {}

    CommissionEmployee(const char* name, int id, double sales, double rate)
        : Employee(name, id), grossSales(sales), commissionRate(rate), commissionSalary(0) {}

    void accept() override {
        Employee::accept();
        cout << "Enter Gross Sales: ";
        cin >> grossSales;
        cout << "Enter Commission Rate: ";
        cin >> commissionRate;
    }

    void display() override {
        Employee::display();
        cout << "Gross Sales: $" << grossSales << endl;
        cout << "Commission Rate: " << commissionRate << endl;
    }

    double earnings() override {
        commissionSalary = grossSales * commissionRate;
        return commissionSalary;
    }
};

int main() {
    SalariedEmployee se;
    HourlyEmployee he;
    CommissionEmployee ce;

    cout << "Enter Salaried Employee Details:" << endl;
    se.accept();
    cout << "\nEnter Hourly Employee Details:" << endl;
    he.accept();
    cout << "\nEnter Commission Employee Details:" << endl;
    ce.accept();

    cout << "\nSalaried Employee:" << endl;
    se.display();
    cout << "Earnings: $" << se.earnings() << endl;

    cout << "\nHourly Employee:" << endl;
    he.display();
    cout << "Earnings: $" << he.earnings() << endl;

    cout << "\nCommission Employee:" << endl;
    ce.display();
    cout << "Earnings: $" << ce.earnings() << endl;

    return 0;
}
