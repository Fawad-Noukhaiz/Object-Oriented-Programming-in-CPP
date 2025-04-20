#include<bits/stdc++.h>

using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositTotal;
    double dailyWithdrawTotal;
    const double dailyDepositLimit;
    const double dailyWithdrawLimit;
    tm lastTransactionDate;

    tm getTodayDate() {
        time_t now = time(nullptr);
        tm today = *localtime(&now);
        today.tm_hour = 0;
        today.tm_min = 0;
        today.tm_sec = 0;
        return today;
    }

    bool isNewDay() {
        tm today = getTodayDate();
        return difftime(mktime(&today), mktime(&lastTransactionDate)) >= 86400;
    }

    void resetDailyTotalsIfNewDay() {
        if (isNewDay()) {
            dailyDepositTotal = 0.0;
            dailyWithdrawTotal = 0.0;
            lastTransactionDate = getTodayDate();
        }
    }

public:
    Wallet(double depositLimit = 10000, double withdrawLimit = 5000)
        : balance(0.0), dailyDepositTotal(0.0), dailyWithdrawTotal(0.0),
          dailyDepositLimit(depositLimit), dailyWithdrawLimit(withdrawLimit) {
        lastTransactionDate = getTodayDate();
    }

    void deposit(double amount) {
        resetDailyTotalsIfNewDay();
        if (amount <= 0)
            throw invalid_argument("Deposit amount must be positive.");
        if (dailyDepositTotal + amount > dailyDepositLimit)
            throw runtime_error("Exceeds daily deposit limit.");
        balance += amount;
        dailyDepositTotal += amount;
        cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << balance << "\n";
    }

    void withdraw(double amount) {
        resetDailyTotalsIfNewDay();
        if (amount <= 0)
            throw invalid_argument("Withdrawal amount must be positive.");
        if (amount > balance)
            throw runtime_error("Insufficient balance.");
        if (dailyWithdrawTotal + amount > dailyWithdrawLimit)
            throw runtime_error("Exceeds daily withdrawal limit.");
        balance -= amount;
        dailyWithdrawTotal += amount;
        cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << "\n";
    }

    double getBalance() const {
        return balance;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string username) : userID(move(id)), name(move(username)) {}

    void deposit(double amount) {
        try {
            wallet.deposit(amount);
        } catch (const exception& e) {
            cout << "[" << name << "] Deposit failed: " << e.what() << "\n";
        }
    }

    void withdraw(double amount) {
        try {
            wallet.withdraw(amount);
        } catch (const exception& e) {
            cout << "[" << name << "] Withdrawal failed: " << e.what() << "\n";
        }
    }

    void checkBalance() const {
        cout << "[" << name << "] Current balance: $" << fixed << setprecision(2) << wallet.getBalance() << "\n";
    }
};

int main() {
    User user1("001", "Alice");
    User user2("002", "Bob");

    user1.deposit(3000);
    user1.withdraw(1000);
    user1.checkBalance();

    user1.withdraw(10000);
    user1.deposit(8000);

    user2.deposit(500);
    user2.withdraw(700);

    user2.checkBalance();

    return 0;
}
