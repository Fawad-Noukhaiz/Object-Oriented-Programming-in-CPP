#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;
    string accountType;

    struct Transaction {
        string type;
        double amount;
        double remainingBalance;
        string date;
    };

    vector<Transaction> transactionHistory;

    string getCurrentDate() {
        time_t now = time(0);
        char* dt = ctime(&now);
        return string(dt);
    }

public:
    Account(string accNumber, string accHolder, double initialBalance = 0.0, string accType = "General")
        : accountNumber(accNumber), accountHolderName(accHolder), balance(initialBalance), accountType(accType) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back({"Deposit", amount, balance, getCurrentDate()});
            cout << "Deposited $" << amount << ". New Balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds! Current Balance: $" << balance << endl;
            return;
        }
        balance -= amount;
        transactionHistory.push_back({"Withdrawal", amount, balance, getCurrentDate()});
        cout << "Withdrawn $" << amount << ". New Balance: $" << balance << endl;
    }

    virtual double calculateInterest() {
        return 0.0;
    }

    void printStatement() {
        cout << "\nTransaction Statement for " << accountHolderName << " (Account: " << accountNumber << ")\n";
        cout << "-------------------------------------------------------------\n";
        cout << left << setw(15) << "Type" << setw(15) << "Amount" << setw(20) << "Balance" << "Date\n";
        cout << "-------------------------------------------------------------\n";

        for (const auto& txn : transactionHistory) {
            cout << left << setw(15) << txn.type << "$" << setw(14) << txn.amount << "$" << setw(18) << txn.remainingBalance << txn.date;
        }
        cout << "-------------------------------------------------------------\n";
    }

    void getAccountInfo() {
        cout << "\nAccount Information:\n";
        cout << "---------------------------------\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "---------------------------------\n";
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNumber, string accHolder, double initialBalance, double rate, double minBalance)
        : Account(accNumber, accHolder, initialBalance, "Savings"), interestRate(rate), minimumBalance(minBalance) {}

    double calculateInterest() override {
        return balance * (interestRate / 100);
    }

    void withdraw(double amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Withdrawal denied! Minimum balance of $" << minimumBalance << " must be maintained." << endl;
            return;
        }
        Account::withdraw(amount);
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNumber, string accHolder, double initialBalance, double overdraft)
        : Account(accNumber, accHolder, initialBalance, "Checking"), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (balance - amount < -overdraftLimit) {
            cout << "Overdraft limit exceeded! Cannot withdraw $" << amount << endl;
            return;
        }
        Account::withdraw(amount);
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    int maturityPeriod;

public:
    FixedDepositAccount(string accNumber, string accHolder, double initialBalance, double rate, int period)
        : Account(accNumber, accHolder, initialBalance, "Fixed Deposit"), fixedInterestRate(rate), maturityPeriod(period) {}

    double calculateInterest() override {
        return balance * (fixedInterestRate / 100) * (maturityPeriod / 12.0);
    }

    void withdraw(double amount) override {
        cout << "Withdrawals not allowed before maturity period of " << maturityPeriod << " months." << endl;
    }
};

int main() {

    SavingsAccount savings("SA123", "Alice Johnson", 2000.0, 3.5, 500.0);
    CheckingAccount checking("CA456", "Bob Smith", 1000.0, 500.0);
    FixedDepositAccount fixedDeposit("FD789", "Charlie Brown", 5000.0, 5.0, 12);

    cout << "\n--- Deposits ---\n";
    savings.deposit(500);
    checking.deposit(700);
    fixedDeposit.deposit(1000);

    cout << "\n--- Withdrawals ---\n";
    savings.withdraw(1800);
    checking.withdraw(1300);
    fixedDeposit.withdraw(500);

    cout << "\n--- Interest Calculations ---\n";
    cout << "Savings Interest: $" << savings.calculateInterest() << endl;
    cout << "Fixed Deposit Interest: $" << fixedDeposit.calculateInterest() << endl;

    cout << "\n--- Account Statements ---\n";
    savings.printStatement();
    checking.printStatement();
    fixedDeposit.printStatement();

    cout << "\n--- Account Info ---\n";
    savings.getAccountInfo();
    checking.getAccountInfo();
    fixedDeposit.getAccountInfo();

    return 0;
}
