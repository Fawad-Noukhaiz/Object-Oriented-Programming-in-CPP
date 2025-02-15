#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    Account() : balance(0) {}

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance" << endl;
        } else {
            balance -= amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account acc;
    acc.credit(1000);
    acc.debit(500);
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}