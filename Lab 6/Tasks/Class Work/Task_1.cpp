#include<bits/stdc++.h>

using namespace std;

class Bank_Account{
    protected:
        static int Acc_no;
        double Accno;
        double balance;

        Bank_Account(){
            balance = 0;
            Acc_no++;
            Accno = Acc_no;
        }
    
    public:
        void Deposit(double Deposit){
            balance += Deposit;
        }

        void Withdraw(double Withdraw){
            if (Withdraw > balance) {
                cout << "Insufficient funds!" << endl;
            } else {
                balance -= Withdraw;
            }
        }

        double GetBalance(){
            return balance;
        }
};

class Savings_Account : public Bank_Account {
    public:
        void Applyinterest(){
            //interest of 6% anually makes 0.5% interest monthly
            balance += balance*0.005; // apply every month
        }
};

class Checking_Account : public Bank_Account {
    private:
        float overdraft;

    public:
        void OverDraft(float Withdraw1){
            if(Withdraw1 <= balance){
                balance -= Withdraw1;
            } else if (Withdraw1 > balance) {
                balance = 0;
                overdraft = Withdraw1 - balance;
                    if (overdraft > 5000){
                        cout << "Alert! Overdraft Limit Exceeded" << endl;
                    }
            }
        }
};

class Business_Account : public Bank_Account {
    private:
        float CorporateTax;

    public:
        void Tax(float Deposit1) {
            CorporateTax = Deposit1*0.02;
            Deposit(Deposit1 - CorporateTax);
        }
};

int Bank_Account :: Acc_no = 0;

class Customer {
    private:
        string name;
        Savings_Account savings;
        Checking_Account checking;
        Business_Account business;

    public:
        Customer(string n) : name(n) {}

        void DepositToSavings(double amount) {
            savings.Deposit(amount);
        }

        void WithdrawFromSavings(double amount) {
            savings.Withdraw(amount);
        }

        void DepositToChecking(double amount) {
            checking.Deposit(amount);
        }

        void WithdrawFromChecking(double amount) {
            checking.Withdraw(amount);
        }

        void DepositToBusiness(double amount) {
            business.Deposit(amount);
        }

        void WithdrawFromBusiness(double amount) {
            business.Withdraw(amount);
        }
};

class Employee {
    protected:
        string name;

    public:
        Employee(string n) : name(n) {}
};

class Teller : public Employee {
    public:
        Teller(string n) : Employee(n) {}

        void FreezeAccount(Bank_Account& account) {
            cout << "Teller " << name << " has frozen the account.\n";
        }
};

class Manager : public Employee {
    public:
        Manager(string n) : Employee(n) {}

        void OverrideAccountLimit(Bank_Account& account, double newLimit) {
            cout << "Manager " << name << " has overridden the account limit to " << newLimit << ".\n";
        }
};

int main() {
    Customer customer1("John Doe");

    customer1.DepositToSavings(1000);
    customer1.WithdrawFromSavings(200);

    customer1.DepositToChecking(1500);
    customer1.WithdrawFromChecking(500);

    customer1.DepositToBusiness(5000);
    customer1.WithdrawFromBusiness(1000);

    Teller teller1("Alice");
    Savings_Account savings;
    teller1.FreezeAccount(savings);

    Manager manager1("Bob");
    Checking_Account checking;
    manager1.OverrideAccountLimit(checking, 10000);

    return 0;
}
