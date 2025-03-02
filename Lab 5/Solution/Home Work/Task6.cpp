#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class CoffeeShop {
public:
    const string Name = "Chai Point";
    vector<string> Menu = {"Chai", "Coffee", "Sandwich", "Cake", "Juice"};
    vector<string> Orders;
    vector<double> Prices = {50, 100, 200, 150, 80};

    void addOrder(const string& item) {
        if (find(Menu.begin(), Menu.end(), item) != Menu.end()) {
            Orders.push_back(item);
            cout << item << " added to orders." << endl;
        } else {
            cout << "This item is currently unavailable!" << endl;
        }
    }

    void fulfillOrder() {
        if (!Orders.empty()) {
            cout << "The " << Orders.front() << " is ready!" << endl;
            Orders.erase(Orders.begin());
        } else {
            cout << "All orders have been fulfilled!" << endl;
        }
    }

    void listOrders() const {
        if (!Orders.empty()) {
            cout << "Orders: ";
            for (const auto& order : Orders) {
                cout << order << " ";
            }
            cout << endl;
        } else {
            cout << "No orders taken." << endl;
        }
    }

    double dueAmount() const {
        double total = 0;
        for (const auto& order : Orders) {
            auto it = find(Menu.begin(), Menu.end(), order);
            if (it != Menu.end()) {
                int index = distance(Menu.begin(), it);
                total += Prices[index];
            }
        }
        return total;
    }

    string cheapestItem() const {
        auto minPrice = min_element(Prices.begin(), Prices.end());
        int index = distance(Prices.begin(), minPrice);
        return Menu[index];
    }

    vector<string> drinksOnly() const {
        vector<string> drinks = {"Chai", "Coffee", "Juice"};
        return drinks;
    }

    vector<string> foodOnly() const {
        vector<string> food = {"Sandwich", "Cake"};
        return food;
    }
};

int main() {
    CoffeeShop shop;
    shop.addOrder("Chai");
    shop.addOrder("Cake");
    shop.listOrders();
    cout << "Total Due: " << shop.dueAmount() << endl;
    shop.fulfillOrder();
    shop.listOrders();
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    cout << "Drinks: ";
    for (const auto& drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;
    cout << "Food: ";
    for (const auto& food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;
    return 0;
}