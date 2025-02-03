#include <iostream>
#include <cstring>
using namespace std;

struct Employee {
    int employee_id;
    string name;
    float salary;
};

struct Organization {
    string organisation_name;
    string organisation_number;
    Employee emp;
};

int main() {
    Organization org = {"NU-Fast", "NUFAST123ABC", {127, "Linus Sebastian", 400000}};
    
    cout << "The size of structure organisation : " << sizeof(org) << endl;
    cout << "Organisation Name : " << org.organisation_name << endl;
    cout << "Organisation Number : " << org.organisation_number << endl;
    cout << "Employee id : " << org.emp.employee_id << endl;
    cout << "Employee name : " << org.emp.name << endl;
    cout << "Employee Salary : " << org.emp.salary << endl;
    
    return 0;
}