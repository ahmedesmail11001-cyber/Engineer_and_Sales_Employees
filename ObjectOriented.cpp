#include <iostream>
#include "Person.h"
using namespace std;

// Parent class
class Employee {
protected:
    string Name;
    int Emp_id;
    double Salary;

public:
    // Constructor overloading

    // Default Constructor
    Employee() {
        Name = "UNKNOWN";
        Emp_id = 0;
        Salary = 0.0;
    }

    // Parameterized Constructor
    Employee(string n, int id, double s): Name(n), Emp_id(id), Salary(s)
    {
    }

    // Pure virtual function --> "Must be overrided in the derived classes"
    virtual double Get_TotalSalary() = 0;

    // Virtual function
    virtual void print() {
        cout << "The employee name is " << Name << " The employee id is " << Emp_id
        <<" the employee salary is $" << Salary << " ";
    }

};

class Sales : public Employee {
private:
    double Goss_Sales;
    double Commission_Rate;

public:
    Sales(string n, int id, double s, double GS, double SCR):Employee(n, id, s)
    {
        Goss_Sales = GS;
        Commission_Rate = SCR;
    }

    double Get_TotalSalary() {
        // implementation of calc the salary for sales employee
        return Salary + Goss_Sales*Commission_Rate;
    }

    void print() {
        Employee::print();
        cout << " the Goss-Sales is: " << Goss_Sales << " the commission rate is "
        << Commission_Rate << '\n';
    }


    // local functions:
    void Set_Gross_Sales(double s) {
        Goss_Sales = s;
    }

    void Set_Commission_Rate(double set_CR) {
        Commission_Rate = set_CR;
    }

    friend void print_GS_and_CR(Sales s);
};

// Applying friend function concepts

void print_GS_and_CR(Sales s) {
    cout << "The gross salses of the sales employee is: " <<s.Goss_Sales << " and the commission rate is:"
    << s.Commission_Rate << '\n';
}


class Engineer : public Employee {
private:
    string Specialty;
    int Experience;
    int overtime_hours;
    double overtime_hour_rate;

public:
    Engineer(string n, int id, double s, string spec, int ex, int overHours, double overHourRate)
        : Employee(n, id, s) {
        Specialty = spec;
        Experience = ex;
        overtime_hours = overHours;
        overtime_hour_rate = overHourRate;
    }

    double Get_TotalSalary() {
        return Salary + overtime_hours*overtime_hour_rate;
    }

    void print() {
        Employee::print();
        cout << "Department: " << Specialty << ' ' << Experience << "years " << overtime_hours << "hour $" << overtime_hour_rate;
    }

    void set_overtime_hours(int hours) {
        overtime_hours = hours;
    }

    void set_overtime_hour_rate(double rate) {
        overtime_hour_rate = rate;
    }


};

int main() {

    Sales s1("Ahmed", 201, 15000.0, 1000, 120);
    Engineer e1("Ismail", 202, 20000, "Information systems", 6, 10, 500 );

    // Polymorphism
    Employee *emp_ptr;

    emp_ptr = &s1;
    cout << emp_ptr->Get_TotalSalary()<< '\n';

    cout << "####################" << '\n';

    emp_ptr = &e1;
    cout << emp_ptr->Get_TotalSalary() << '\n';


}