#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int id;
    string name;
};

bool compareById(const Person &a, const Person &b) {
    return a.id < b.id;
}

bool compareByName(const Person &a, const Person &b) {
    return a.name < b.name;
}

int main() {
    int N;
    cout << "Enter number of people: ";
    cin >> N;
    vector<Person> people(N);
    
    for (int i = 0; i < N; i++) {
        cout << "Enter ID and Name: ";
        cin >> people[i].id >> people[i].name;
    }
    
    sort(people.begin(), people.end(), compareById);
    cout << "Sorted by ID:" << endl;
    for (const auto& p : people) {
        cout << p.id << " " << p.name << endl;
    }
    
    sort(people.begin(), people.end(), compareByName);
    cout << "Sorted by Name:" << endl;
    for (const auto& p : people) {
        cout << p.id << " " << p.name << endl;
    }
    
    return 0;
}
