#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
private:
    string name;
    int id;

public:
    Car(string carName, int carId) : name(carName), id(carId) {}

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }
};

class Garage {
private:
    vector<Car*> cars;

public:
    void parkCar(Car* car) {
        cars.push_back(car);
        cout << "Car " << car->getName() << " (ID: " << car->getId() << ") parked in the garage." << endl;
    }

    void listCars() const {
        if (cars.empty()) {
            cout << "No cars in the garage." << endl;
        } else {
            cout << "Cars currently parked in the garage:" << endl;
            for (const auto& car : cars) {
                cout << " - " << car->getName() << " (ID: " << car->getId() << ")" << endl;
            }
        }
    }
};

int main() {
    Car car1("Toyota", 101);
    Car car2("Honda", 102);
    Car car3("Suzuki", 103);

    Garage garage;

    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    garage.listCars();

    {
        Car tempCar("Tesla", 104);
        garage.parkCar(&tempCar);
        garage.listCars();
    }

    cout << "\nAfter tempCar goes out of scope:" << endl;
    garage.listCars();

    return 0;
}