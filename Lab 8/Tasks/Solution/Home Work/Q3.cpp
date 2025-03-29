#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    int employeeID;

public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }

    void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }

    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
};

class Accounts : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }

    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
};

int main() {
    Admin adminEmployee;
    Accounts accountsEmployee;

    cout << "Enter details for Admin Employee:\n";
    adminEmployee.getData();
    cout << "\nEnter details for Accounts Employee:\n";
    accountsEmployee.getData();

    cout << "\nAdmin Employee Details:\n";
    adminEmployee.displayData();
    cout << "\nAccounts Employee Details:\n";
    accountsEmployee.displayData();

    return 0;
}
