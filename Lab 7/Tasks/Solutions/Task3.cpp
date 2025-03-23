#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate) 
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    virtual void displayCurrency() {
        cout << currencySymbol << fixed << setprecision(2) << amount << " (" << currencyCode << ")" << endl;
    }

    virtual double convertTo(Currency& targetCurrency) {
        double baseValue = convertToBase();
        return baseValue / targetCurrency.exchangeRate;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.10) {}
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.012) {}
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee inr(5000);

    cout << "Currency Conversion System\n-------------------------" << endl;
    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    cout << "\nConverting 100 USD to Euro: " << eur.convertTo(usd) << " EUR" << endl;
    cout << "Converting 5000 INR to USD: " << usd.convertTo(inr) << " USD" << endl;

    return 0;
}
