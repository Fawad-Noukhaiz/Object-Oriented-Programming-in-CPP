/*Task - 03: We are prototyping a robot that refills glasses during dinner. Every glass holds 200 milliliters. During dinner, people either drink water or juice, and as soon as there is less than 100 ml left in the glass, the robot refills it back to 200 ml. Create a class Glass with one public int field LiquidLevel and methods public Drink(int milliliters) that takes the amount of liquid that a person drank and public Refill() that refills the glass to be 200 ml full. Both methods should not return any value. Initially set LiquidLevel  to 200. In the Main method create an object of class Glass and read commands from the screen until the user terminates the program (see next). Don't forget to refill the glass when needed! */

#include <iostream>
#include <string>
using namespace std;

class Glass {
public:
    int LiquidLevel;

    Glass() : LiquidLevel(200) {}

    void Drink(int milliliters) {
        LiquidLevel -= milliliters;
        if (LiquidLevel < 100) {
            Refill();
        }
    }

    void Refill() {
        LiquidLevel = 200;
        cout << "Glass refilled to 200 ml." << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: <program> <command>" << endl;
        return 1;
    }

    Glass glass;
    string command = argv[1];
    if (command == "drink") {
        if (argc != 3) {
            cout << "Usage: <program> drink <amount>" << endl;
            return 1;
        }
        int amount = stoi(argv[2]);
        glass.Drink(amount);
        cout << "Remaining liquid: " << glass.LiquidLevel << " ml." << endl;
    } else if (command == "exit") {
        return 0;
    } else {
        cout << "Invalid command" << endl;
    }

    return 0;
}
