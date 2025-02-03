#include <iostream>
using namespace std;

void* addToArray(void *arr, int size, int addValue) {
    int *intArr = static_cast<int*>(arr);
    for (int i = 0; i < size; i++) {
        intArr[i] += addValue;
    }
    return static_cast<void*>(intArr);
}

int main(int argc, char *argv[]) {
    int size = argc - 2;
    int addValue = atoi(argv[1]);
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = atoi(argv[i + 2]);
    }
    addToArray(static_cast<void*>(arr), size, addValue);
    cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}