#include <bits/stdc++.h>

using namespace std;

class Employee{
    protected:
        string Name;
        int ID;

    public:
    Employee() {}

    Employee(string Name1, int ID1) {
        Name = Name1;
        ID = ID1;
    }

    void displayInfo() {
        cout << "Name: " << Name << ", ID: " << ID << endl;
    }
};

class IOrderTaker{
    public:
        void takeOrder(){
            cout << "Taking Order..." << endl;
        }
};

class IOrderPreparer{
    public:
        void preparingOrder(){
            cout << "Preparing Order..." << endl;
        }
};

class IBiller{
    public:
        void Bill(){
            cout << "Billing..." << endl;
        }
};

class Waiter : public Employee, public IOrderTaker {
    public:
        Waiter() {}
        Waiter(string Name1, int ID1) : Employee(Name1,ID1) {}
};

class Chef : public Employee, public IOrderPreparer {
    public:
        Chef() {}
        Chef(string Name1, int ID1) : Employee(Name1,ID1) {}
};

class Cashier : public Employee, public IBiller {
    public:
        Cashier() {}
        Cashier(string Name1, int ID1) : Employee(Name1,ID1) {}
};

class Manager : public Employee, public IOrderTaker, public IBiller {
    public:
        Manager() {}
        Manager(string Name1, int ID1) : Employee(Name1,ID1) {}
};

int main() {
    Waiter w("Alice", 101);
    w.displayInfo();  
    w.takeOrder();   // ✅ Now accessible

    Chef c("Bob", 102);
    c.displayInfo();
    c.preparingOrder();  // ✅ Now accessible

    Cashier ca("Charlie", 103);
    ca.displayInfo();
    ca.Bill();  // ✅ Now accessible

    Manager m("David", 104);
    m.displayInfo();
    m.takeOrder();  // ✅ Manager can take orders
    m.Bill();       // ✅ Manager can also bill

    return 0;
}