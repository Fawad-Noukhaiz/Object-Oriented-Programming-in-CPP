#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    int id;
    string name;
public:
    void getStudentDetails() {
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);
    }
    void displayStudentDetails() {
        cout << "Student ID: " << id << "\nName: " << name << "\n";
    }
};

class Marks : public Student {
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;
public:
    void getMarks() {
        cout << "Enter marks for OOP: ";
        cin >> marks_oop;
        cout << "Enter marks for PF: ";
        cin >> marks_pf;
        cout << "Enter marks for DS: ";
        cin >> marks_ds;
        cout << "Enter marks for DB: ";
        cin >> marks_db;
    }
    void displayMarks() {
        cout << "Marks in OOP: " << marks_oop << "\nMarks in PF: " << marks_pf
             << "\nMarks in DS: " << marks_ds << "\nMarks in DB: " << marks_db << "\n";
    }
};

class Result : public Marks {
private:
    int total_marks;
    double avg_marks;
public:
    void calculateResult() {
        total_marks = marks_oop + marks_pf + marks_ds + marks_db;
        avg_marks = total_marks / 4.0;
    }
    void displayResult() {
        cout << "Total Marks: " << total_marks << "\nAverage Marks: " << avg_marks << "\n";
    }
};

int main() {
    Result studentResult;
    
    studentResult.getStudentDetails();
    studentResult.getMarks();
    studentResult.calculateResult();
    
    cout << "\nStudent Details:" << endl;
    studentResult.displayStudentDetails();
    
    cout << "Marks Obtained:" << endl;
    studentResult.displayMarks();
    
    cout << "Result:" << endl;
    studentResult.displayResult();
    
    return 0;
}