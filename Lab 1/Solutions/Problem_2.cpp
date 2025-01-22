//Write a program that calculates the sum of all the elements in array using pointers

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;

    cout << "Enter the number of Elements" << endl;
    cin >> n;

    int arr[n];

    for (int i = 0 ; i < n ; i++)
    {
        cout << "Enter element " << i+1 << " : ";
        cin >> arr[i];
    }
    
    int* ptr = arr;

    int sum = 0;

    for (int i = 0 ; i < n ; i++)
    {
        sum += *ptr;
        ptr++;
    }

    cout << "Sum of all elements in the array: " << sum << endl;

    return 0;
}