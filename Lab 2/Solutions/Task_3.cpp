#include <iostream>
using namespace std;

void resizeArray(int *&arr, int &capacity, int newSize) {
    int *newArr = new int[newSize];
    for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newSize;
}

int main() {
    int capacity = 5;
    int size = 0;
    int *arr = new int[capacity];
    
    int input;
    cout << "Enter numbers (-1 to stop):\n";
    while (cin >> input && input != -1) {
        if (size >= capacity) {
            resizeArray(arr, capacity, capacity * 2);
        }
        arr[size++] = input;
    }
    
    resizeArray(arr, capacity, size);
    
    cout << "Final array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;
    return 0;
}