#include <iostream>
#include <string>
using namespace std;

class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}
    virtual void display() {
        cout << "Price: $" << price << endl;
    }
};

class Car : public Vehicles {
protected:
    int seating_capacity;
    int num_doors;
    string fuel_type;
public:
    Car(double p, int seat, int doors, string fuel) : Vehicles(p), seating_capacity(seat), num_doors(doors), fuel_type(fuel) {}
    void display() override {
        Vehicles::display();
        cout << "Seating Capacity: " << seating_capacity << "\nNumber of Doors: " << num_doors << "\nFuel Type: " << fuel_type << "\n";
    }
};

class Motorcycle : public Vehicles {
protected:
    int num_cylinders;
    int num_gears;
    int num_wheels;
public:
    Motorcycle(double p, int cylinders, int gears, int wheels) : Vehicles(p), num_cylinders(cylinders), num_gears(gears), num_wheels(wheels) {}
    void display() override {
        Vehicles::display();
        cout << "Number of Cylinders: " << num_cylinders << "\nNumber of Gears: " << num_gears << "\nNumber of Wheels: " << num_wheels << "\n";
    }
};

class Audi : public Car {
private:
    string model_type;
public:
    Audi(double p, int seat, int doors, string fuel, string model) : Car(p, seat, doors, fuel), model_type(model) {}
    void display() override {
        Car::display();
        cout << "Model Type: " << model_type << "\n" << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string make_type;
public:
    Yamaha(double p, int cylinders, int gears, int wheels, string make) : Motorcycle(p, cylinders, gears, wheels), make_type(make) {}
    void display() override {
        Motorcycle::display();
        cout << "Make Type: " << make_type << "\n" << endl;
    }
};

int main() {
    Audi audiCar(50000, 5, 4, "Petrol", "A6");
    Yamaha yamahaBike(15000, 2, 6, 2, "R1");
    
    cout << "Audi Car Details:" << endl;
    audiCar.display();
    
    cout << "Yamaha Motorcycle Details:" << endl;
    yamahaBike.display();
    
    return 0;
}