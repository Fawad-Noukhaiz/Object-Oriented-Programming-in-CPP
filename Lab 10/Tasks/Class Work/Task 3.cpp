#include<bits/stdc++.h>

using namespace std;

struct User {
    string user_id, first_name, last_name, address, email;
};

struct Product {
    string product_id, product_name, description;
    int price;
};

struct Order {
    string order_id, user_id, product_id;
    int total_paid;
};

vector<User> readUsers(const string& filename) {
    vector<User> users;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        User u;
        ss >> u.user_id >> u.first_name >> u.last_name >> u.address >> u.email;
        users.push_back(u);
    }
    file.close();
    return users;
}

vector<Product> readProducts(const string& filename) {
    vector<Product> products;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Product p;
        ss >> p.product_id >> p.product_name >> p.description >> p.price;
        products.push_back(p);
    }
    file.close();
    return products;
}

vector<Order> readOrders(const string& filename) {
    vector<Order> orders;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Order o;
        ss >> o.order_id >> o.user_id >> o.product_id >> o.total_paid;
        orders.push_back(o);
    }
    file.close();
    return orders;
}

void writeUsers(const string& filename, const vector<User>& users) {
    ofstream file(filename);
    for (const auto& u : users) {
        file << u.user_id << " " << u.first_name << " " << u.last_name << " " << u.address << " " << u.email << endl;
    }
    file.close();
}

void writeProducts(const string& filename, const vector<Product>& products) {
    ofstream file(filename);
    for (const auto& p : products) {
        file << p.product_id << " " << p.product_name << " " << p.description << " " << p.price << endl;
    }
    file.close();
}

void writeOrders(const string& filename, const vector<Order>& orders) {
    ofstream file(filename);
    for (const auto& o : orders) {
        file << o.order_id << " " << o.user_id << " " << o.product_id << " " << o.total_paid << endl;
    }
    file.close();
}

int main() {
    vector<User> users = {
        {"u1", "Fawad", "Noukhaiz", "Karachi", "fawad@example.com"},
        {"u2", "Person", "2", "Lahore", "p2@example.com"},
        {"u3", "Person", "3", "Islamabad", "p3@example.com"}
    };

    vector<Product> products = {
        {"p1", "Laptop", "HighEndLaptop", 2000},
        {"p2", "Phone", "Smartphone", 800},
        {"p3", "Tablet", "TabletDevice", 600}
    };

    vector<Order> orders = {
        {"o1", "u1", "p1", 2000},
        {"o2", "u2", "p2", 800},
        {"o3", "u1", "p3", 600}
    };

    writeUsers("users.txt", users);
    writeProducts("products.txt", products);
    writeOrders("orders.txt", orders);

    vector<User> read_users = readUsers("users.txt");
    vector<Product> read_products = readProducts("products.txt");
    vector<Order> read_orders = readOrders("orders.txt");

    string target_user_id = "";
    for (auto& user : read_users) {
        if (user.first_name == "Linus") {
            target_user_id = user.user_id;
            break;
        }
    }

    vector<string> product_ids;
    for (auto& order : read_orders) {
        if (order.user_id == target_user_id) {
            product_ids.push_back(order.product_id);
        }
    }

    for (auto& pid : product_ids) {
        for (auto& product : read_products) {
            if (product.product_id == pid) {
                cout << product.product_name << endl;
            }
        }
    }

    return 0;
}
