#include <bits/stdc++.h>

using namespace std;

class Person {
protected:
    string name;
    int id;
    double salary;

public:
    virtual void getdata() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    virtual void displaydata() const {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }

    virtual void bonus() const {
        cout << "Bonus: " << 0.1 * salary << endl;
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getdata() override {
        cout << "[Admin] ";
        Person::getdata();
    }

    void displaydata() const override {
        cout << "[Admin] ";
        Person::displaydata();
    }

    void bonus() const override {
        cout << "[Admin Bonus] " << 0.15 * salary << endl;
    }
};

class Account : virtual public Person {
public:
    void getdata() override {
        cout << "[Account] ";
        Person::getdata();
    }

    void displaydata() const override {
        cout << "[Account] ";
        Person::displaydata();
    }

    void bonus() const override {
        cout << "[Account Bonus] " << 0.12 * salary << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getdata() override {
        cout << "[Master] ";
        Person::getdata();
    }

    void displaydata() const override {
        cout << "[Master] ";
        Person::displaydata();
    }

    void bonus() const override {
        cout << "[Master Bonus] " << 0.2 * salary << endl;
    }
};

int main() {
    Person* ptr;

    Admin a;
    Account acc;
    Master m;

    cout << "\nEnter Admin Data:\n";
    ptr = &a;
    ptr->getdata();
    ptr->displaydata();
    ptr->bonus();

    cout << "\nEnter Account Data:\n";
    ptr = &acc;
    ptr->getdata();
    ptr->displaydata();
    ptr->bonus();

    cout << "\nEnter Master Data:\n";
    ptr = &m;
    ptr->getdata();
    ptr->displaydata();
    ptr->bonus();

    return 0;
}
