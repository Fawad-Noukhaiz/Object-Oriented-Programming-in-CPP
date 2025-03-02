#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Grind {
public:
    void grindJuice() {
        cout << "Grinding fruits..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Grinding complete!" << endl;
    }
};

class Blend {
public:
    void blendJuice() {
        cout << "Blending fruits..." << endl;
        for (int i = 1; i <= 5; ++i) {
            cout << "Blending step " << i << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "Blending complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blend;
    Grind grind;

public:
    void makeJuice() {
        grind.grindJuice();
        blend.blendJuice();
        cout << "Juice is ready!" << endl;
    }
};

int main() {
    JuiceMaker juiceMaker;
    juiceMaker.makeJuice();
    return 0;
}