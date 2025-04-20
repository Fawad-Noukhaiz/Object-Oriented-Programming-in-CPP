#include <bits/stdc++.h>

using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(string m) : model(move(m)), price(0.0) {}

    string getModel() const {
        return model;
    }

    double getPrice() const {
        return price;
    }

    void setModel(const string& m) {
        model = m;
    }

    virtual void setPrice(double p) = 0;

    virtual ~Car() {}
};

class Color : public Car {
private:
    string color;
public:
    Color(string m, string c) : Car(move(m)), color(move(c)) {}

    void setPrice(double p) override {
        price = p + 1000;
    }

    void showDetails() const {
        cout << "Model: " << model << ", Color: " << color << ", Price: $" << price << endl;
    }
};

class Company : public Car {
private:
    string company;
public:
    Company(string m, string comp) : Car(move(m)), company(move(comp)) {}

    void setPrice(double p) override {
        price = p + 2000;
    }

    void showDetails() const {
        cout << "Model: " << model << ", Company: " << company << ", Price: $" << price << endl;
    }
};

int main() {
    Color coloredCar("Model X", "Red");
    coloredCar.setPrice(25000);
    coloredCar.showDetails();

    Company companyCar("Model Y", "Tesla");
    companyCar.setPrice(30000);
    companyCar.showDetails();

    return 0;
}
