#include <iostream>
#include <any>
#include <exception>

using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Bad type requested";
    }
};

class TypeSafeContainer {
    any data;
public:
    template<typename T>
    void store(const T& value) {
        data = value;
    }

    template<typename T>
    T get() const {
        if (!data.has_value() || data.type() != typeid(T))
            throw BadTypeException();
        return any_cast<T>(data);
    }
};

int main() {
    TypeSafeContainer c;
    c.store<int>(100);
    try {
        cout << c.get<int>() << endl;
        cout << c.get<string>() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
