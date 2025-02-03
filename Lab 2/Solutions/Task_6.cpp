#include <iostream>
#include <vector>
using namespace std;

struct Subject {
    string name;
};

struct Student {
    int id;
    vector<Subject> subjects;
};

int main() {
    int numStudents, numSubjects;
    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << "Enter number of subjects per student: ";
    cin >> numSubjects;
    
    vector<Student> students(numStudents);
    
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter ID for student " << i + 1 << ": ";
        cin >> students[i].id;
        students[i].subjects.resize(numSubjects);
        
        for (int j = 0; j < numSubjects; j++) {
            cout << "Enter subject " << j + 1 << " for student " << students[i].id << ": ";
            cin >> students[i].subjects[j].name;
        }
    }
    
    cout << "\nStudent Data:\n";
    for (const auto& student : students) {
        cout << "ID: " << student.id << " Subjects: ";
        for (const auto& subject : student.subjects) {
            cout << subject.name << " ";
        }
        cout << endl;
    }
    
    return 0;
}