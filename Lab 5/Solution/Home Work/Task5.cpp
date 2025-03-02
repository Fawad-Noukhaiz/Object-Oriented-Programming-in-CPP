#include <iostream>

using namespace std;

class Car {
public:
    int engine_horsepower;
    int seating_capacity;
    int no_of_speakers;

    void setValues(int hp, int seats, int speakers) const {
        const_cast<Car*>(this)->engine_horsepower = hp;
        const_cast<Car*>(this)->seating_capacity = seats;
        const_cast<Car*>(this)->no_of_speakers = speakers;
    }

    void display() const {
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }
};

int main() {
    Car car;
    car.setValues(150, 5, 4);
    car.display();
    return 0;
}