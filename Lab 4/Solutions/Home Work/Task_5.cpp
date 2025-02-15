#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct MenuItem {
    string name;
    string type;
    double price;
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string n, vector<MenuItem> m) : name(n), menu(m) {}

    string addOrder(const string& itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added";
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() const {
        return orders;
    }

    double dueAmount() const {
        double total = 0;
        for (const auto& item : orders) {
            for (const auto& menuItem : menu) {
                if (menuItem.name == item) {
                    total += menuItem.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() const {
        auto it = min_element(menu.begin(), menu.end(), [](const MenuItem& a, const MenuItem& b) {
            return a.price < b.price;
        });
        return it->name;
    }

    vector<string> drinksOnly() const {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() const {
        vector<string> food;
        for (const auto& item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    vector<MenuItem> menu = {
        {"Coffee", "drink", 2.5},
        {"Tea", "drink", 2.0},
        {"Sandwich", "food", 5.0}
    };

    CoffeeShop shop("My Coffee Shop", menu);
    cout << shop.addOrder("Coffee") << endl;
    cout << shop.fulfillOrder() << endl;
    cout << "Due Amount: " << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    return 0;
}