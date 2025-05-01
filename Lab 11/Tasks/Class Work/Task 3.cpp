#include <iostream>
#include <exception>

using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds";
    }
};

template<typename T>
class SafeArray {
    T* data;
    size_t size;
public:
    SafeArray(size_t s) : size(s) {
        data = new T[s];
    }

    ~SafeArray() {
        delete[] data;
    }

    T& operator[](int index) {
        if (index < 0 || static_cast<size_t>(index) >= size)
            throw ArrayIndexOutOfBounds();
        return data[index];
    }
};

int main() {
    SafeArray<int> arr(5);
    for (int i = 0; i < 5; ++i)
        arr[i] = i * 10;
    try {
        cout << arr[2] << endl;
        cout << arr[10] << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
