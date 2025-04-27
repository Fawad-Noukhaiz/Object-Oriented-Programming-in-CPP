#include<bits/stdc++.h>

using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years;
};

vector<Employee> readData(const string& filename) {
    vector<Employee> employees;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Employee emp;
        ss >> emp.id >> emp.name >> emp.designation >> emp.years;
        employees.push_back(emp);
    }
    file.close();
    return employees;
}

void writeData(const string& filename, const vector<Employee>& employees) {
    ofstream file(filename);
    for (const auto& emp : employees) {
        file << emp.id << " " << emp.name << " " << emp.designation << " " << emp.years << endl;
    }
    file.close();
}

vector<Employee> queryManagers(const vector<Employee>& employees) {
    vector<Employee> managers;
    for (const auto& emp : employees) {
        if (emp.designation == "manager" && emp.years >= 2) {
            managers.push_back(emp);
        }
    }
    return managers;
}

void incrementData(vector<Employee>& employees) {
    for (auto& emp : employees) {
        emp.id += 1;
        emp.years += 1;
    }
}

int main() {
    string filename = "employees.txt";

    vector<Employee> initial = {
        {1, "Person 1", "developer", 1},
        {2, "Person 2", "manager", 3},
        {3, "Person 3", "designer", 2},
        {4, "Person 4", "manager", 1},
        {5, "Person 5", "manager", 4}
    };

    writeData(filename, initial);

    vector<Employee> employees = readData(filename);

    vector<Employee> managers = queryManagers(employees);

    writeData(filename, managers);

    incrementData(managers);

    writeData(filename, managers);

    return 0;
}
