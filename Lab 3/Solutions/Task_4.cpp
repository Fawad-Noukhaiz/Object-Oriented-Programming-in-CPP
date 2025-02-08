/*Task - 04: Create a class called Employee that includes three pieces of information as instance variables—a first name (type String), a last name (type String) and a monthly salary (double). If the monthly salary is not positive, set it to 0.0. Write a test application named EmployeeTest that demonstrates class Employee’s capabilities. Create two Employee objects and display each object’s yearly salary. Then give each Employee a 10% raise and display each Employee’s yearly salary again.*/

#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
    Employee(string fName, string lName, double salary)
        : firstName(fName), lastName(lName) {
        monthlySalary = salary > 0 ? salary : 0.0;
    }

    double getYearlySalary() {
        return monthlySalary * 12;
    }

    void applyRaise() {
        monthlySalary *= 1.10;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 7) {
        cout << "Usage: <program> <first_name> <last_name> <salary1> <first_name2> <last_name2> <salary2>" << endl;
        return 1;
    }

    string firstName1 = argv[1];
    string lastName1 = argv[2];
    double salary1 = stod(argv[3]);

    string firstName2 = argv[4];
    string lastName2 = argv[5];
    double salary2 = stod(argv[6]);

    Employee emp1(firstName1, lastName1, salary1);
    Employee emp2(firstName2, lastName2, salary2);

    cout << "Employee 1 yearly salary: " << emp1.getYearlySalary() << endl;
    cout << "Employee 2 yearly salary: " << emp2.getYearlySalary() << endl;

    emp1.applyRaise();
    emp2.applyRaise();

    cout << "Employee 1 yearly salary after raise: " << emp1.getYearlySalary() << endl;
    cout << "Employee 2 yearly salary after raise: " << emp2.getYearlySalary() << endl;

    return 0;
}
