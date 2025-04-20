#include <bits/stdc++.h>

using namespace std;

class Passenger;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int totalSeats;
    int bookedEconomy;
    int bookedBusiness;

    unordered_set<string> economyPassengers;
    unordered_set<string> businessPassengers;

    bool isBooked(const Passenger& p) const;

public:
    Flight(string number, string from, string to, int capacity)
        : flightNumber(move(number)), departure(move(from)), arrival(move(to)),
          totalSeats(capacity), bookedEconomy(0), bookedBusiness(0) {}

    bool bookSeat(const Passenger& p);
    bool cancelSeat(const Passenger& p);
    bool upgradeSeat(const Passenger& p);

    void flightStatus() const;

    friend class Passenger;
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(string pid, string pname) : id(move(pid)), name(move(pname)) {}

    bool requestBooking(Flight& flight) {
        return flight.bookSeat(*this);
    }

    bool requestCancellation(Flight& flight) {
        return flight.cancelSeat(*this);
    }

    bool requestUpgrade(Flight& flight) {
        return flight.upgradeSeat(*this);
    }

    string getID() const {
        return id;
    }

    string getName() const {
        return name;
    }
};

bool Flight::isBooked(const Passenger& p) const {
    return economyPassengers.count(p.getID()) || businessPassengers.count(p.getID());
}

bool Flight::bookSeat(const Passenger& p) {
    if (bookedEconomy + bookedBusiness >= totalSeats) {
        cout << "Booking failed for " << p.getName() << ": Flight is full.\n";
        return false;
    }
    if (isBooked(p)) {
        cout << "Booking failed for " << p.getName() << ": Already booked.\n";
        return false;
    }
    economyPassengers.insert(p.getID());
    bookedEconomy++;
    cout << "Seat booked in Economy for " << p.getName() << ".\n";
    return true;
}

bool Flight::cancelSeat(const Passenger& p) {
    if (economyPassengers.erase(p.getID())) {
        bookedEconomy--;
        cout << p.getName() << " canceled Economy seat.\n";
        return true;
    } else if (businessPassengers.erase(p.getID())) {
        bookedBusiness--;
        cout << p.getName() << " canceled Business seat.\n";
        return true;
    } else {
        cout << "Cancellation failed for " << p.getName() << ": No booking found.\n";
        return false;
    }
}

bool Flight::upgradeSeat(const Passenger& p) {
    if (!economyPassengers.count(p.getID())) {
        cout << "Upgrade failed for " << p.getName() << ": Not in Economy class.\n";
        return false;
    }
    economyPassengers.erase(p.getID());
    businessPassengers.insert(p.getID());
    bookedEconomy--;
    bookedBusiness++;
    cout << p.getName() << " upgraded to Business class.\n";
    return true;
}

void Flight::flightStatus() const {
    cout << "\n[Flight Status: " << flightNumber << "]\n";
    cout << "Route: " << departure << " -> " << arrival << "\n";
    cout << "Total Capacity: " << totalSeats << "\n";
    cout << "Economy Booked: " << bookedEconomy << "\n";
    cout << "Business Booked: " << bookedBusiness << "\n";
    cout << "Available: " << totalSeats - bookedEconomy - bookedBusiness << "\n\n";
}

int main() {
    Flight flight1("AB123", "New York", "London", 3);
    Passenger alice("P001", "Alice");
    Passenger bob("P002", "Bob");
    Passenger carol("P003", "Carol");
    Passenger dave("P004", "Dave");

    alice.requestBooking(flight1);
    bob.requestBooking(flight1);
    carol.requestBooking(flight1);
    dave.requestBooking(flight1);

    flight1.flightStatus();

    bob.requestUpgrade(flight1);
    alice.requestCancellation(flight1);
    dave.requestBooking(flight1);

    flight1.flightStatus();

    return 0;
}
