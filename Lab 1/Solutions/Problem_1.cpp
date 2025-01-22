//Write a program that finds the second highest number in a float type array of 20 elements using pointer.

#include<iostream>
#include<climits>

using namespace std;

float findSecondHighest(float arr[], int n) {
    float max1 = __FLT_MIN__, max2 = __FLT_MIN__;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
}

int main(){

    float arr[20];

    cout << "Enter 20 floating point numbers: ";
    for(int i=0; i<20; i++)
        cin >> arr[i];


    float secondHighest = findSecondHighest(arr, 20);

    cout << "The second highest number is: " << secondHighest << endl;

    return 0;
}