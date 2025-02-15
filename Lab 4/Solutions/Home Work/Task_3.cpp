#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(string num, string desc, int qty, double price)
        : partNumber(num), partDescription(desc), quantity(qty), pricePerItem(price) {
        if (quantity < 0) quantity = 0;
        if (pricePerItem < 0) pricePerItem = 0.0;
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {
    Invoice inv("1234", "Hammer", 2, 14.95);
    cout << "Invoice Amount: " << inv.getInvoiceAmount() << endl;
    return 0;
}