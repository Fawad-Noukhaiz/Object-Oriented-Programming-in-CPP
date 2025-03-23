#include <iostream>
#include <vector>

using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() {
        cout << "\nID: " << id << "\nName: " << name << "\nAddress: " << address << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, double g, int year)
        : Person(n, i, a, p, e), GPA(g), enrollmentYear(year) {}

    void enrollCourse(string course) {
        coursesEnrolled.push_back(course);
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << "\nCourses: ";
        for (auto& course : coursesEnrolled) cout << course << " ";
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string d, double s)
        : Person(n, i, a, p, e), department(d), salary(s) {}

    void addCourse(string course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses: ";
        for (auto& course : coursesTaught) cout << course << " ";
        cout << endl;
    }
};

int main() {
    Student s1("Alice", "S101", "123 St", "1234567890", "alice@example.com", 3.8, 2022);
    s1.enrollCourse("Math");
    s1.enrollCourse("Physics");

    Professor p1("Dr. Smith", "P202", "456 St", "9876543210", "smith@example.com", "Computer Science", 80000);
    p1.addCourse("Data Structures");

    cout << "\nStudent Information:";
    s1.displayInfo();

    cout << "\nProfessor Information:";
    p1.displayInfo();

    return 0;
}
