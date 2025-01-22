//Write a program in C++ to calculate and print the Electricity bill of a given customer. The customer id, name and unit consumed by the user should be taken from the keyboard and display the total amount to pay to the customer.

#include<iostream>
#include<string>
using namespace std;

int main(){

    int customer_ID;
    string customer_name;
    int units_consumed;

    cout << "Enter Customer ID: ";
    cin >> customer_ID;

    cout << "Enter Name: ";
    cin >> customer_name;

    cout << "Enter Units Consumed: ";
    cin >> units_consumed;

    float ammount_charges;

    cout << "Customer ID: " << customer_ID << endl;
    cout << "Customer Name: " << customer_name << endl;
    cout << "Units Consumed: " << units_consumed << endl;

    if (units_consumed <= 199)
    {
        ammount_charges = units_consumed * 16.20;
        cout << "Ammount Charges @Rs. 16.20 per unit: " << ammount_charges << endl;
    } else if (units_consumed >= 200 && units_consumed <= 300) {
        ammount_charges = units_consumed * 20.10;
        cout << "Ammount Charges @Rs. 20.10 per unit: " << ammount_charges << endl;
    } else if (units_consumed > 300 && units_consumed <= 500) {
        ammount_charges = units_consumed * 27.10;
        cout << "Ammount Charges @Rs. 27.10 per unit: " << ammount_charges << endl;
    } else if (units_consumed > 500){
        ammount_charges = units_consumed * 35.90;
        cout << "Ammount Charges @Rs. 35.90 per unit: " << ammount_charges << endl;
    }

    if (ammount_charges > 18000)
    {
        float surcharge = ammount_charges * 0.15;
        cout << "Surcharge: " << surcharge << endl;
        float total_amount_to_pay = ammount_charges + surcharge;
        cout << "Net Ammount paid by customer: " << total_amount_to_pay << endl;
    }
    
    return 0;
}