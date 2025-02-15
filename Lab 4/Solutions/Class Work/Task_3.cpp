#include <iostream>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int size;
    int* data;

public:
    DynamicArray() : size(0), data(nullptr) {}

    DynamicArray(int n) : size(n), data(new int[n]{0}) {}

    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = other.data;
            other.size = 0;
            other.data = nullptr;
        }
        return *this;
    }

    int getSize() const { return size; }

    int& at(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    void resize(int newSize) {
        if (newSize < 0) {
            throw invalid_argument("Size cannot be negative");
        }
        int* newData = new int[newSize]{0};
        for (int i = 0; i < min(size, newSize); ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }
};

int main() {
    DynamicArray arr1(5);
    arr1.at(0) = 10;
    cout << "Size: " << arr1.getSize() << endl;

    DynamicArray arr2 = arr1;
    arr2.resize(10);
    cout << "Size: " << arr2.getSize() << endl;

    return 0;
}