#include <iostream>
#include <vector>
using namespace std;

int sumArray(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    vector<int> arr;
    for (int i = 1; i < argc; i++) {
        arr.push_back(atoi(argv[i]));
    }
    cout << "Sum of array elements: " << sumArray(arr.data(), arr.size()) << endl;
    return 0;
}