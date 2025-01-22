//Write a program that reads a student name followed by five test scores. The program should output the student’s name, the five test scores, and the average test score. Output the average test score with two decimal places.

#include<iostream>
#include<string>
using namespace std;

int main(){

    string Name;

    cout << "Enter Your Name: ";
    cin >> Name;

    float score1, score2, score3, score4, score5, average;

    cout << "Enter Your Five Test Scores: ";
    cin >> score1 >> score2 >> score3 >> score4 >> score5;

    average = (score1 + score2 + score3 + score4 + score5) / 5;

    cout << "Name: " << Name << endl;
    cout << "Test Scores: " << score1 << ", " << score2 << ", " << score3 << ", " << score4 << ", " << score5 << endl;
    cout << "Average Test Score: " << average;

    return 0;
}