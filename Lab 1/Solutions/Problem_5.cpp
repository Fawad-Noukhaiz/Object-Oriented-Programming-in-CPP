//A movie in a local theater is in great demand. To help a local charity, the theater owner has decided to donate to the charity a portion of the gross amount generated from the movie. This example designs and implements a program that prompts the user to input the movie name, adult ticket price, child ticket price, number of adult tickets sold, number of child tickets sold, and percentage of the gross amount to be donated to the charity.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    string Movie_Name;
    float Adult_Ticket_Price;
    float Child_Ticket_Price;
    int Number_Of_Adult_Ticket_Sold;
    int Number_Of_Child_Ticket_Sold;
    float Percentage_To_Be_Donated;

    cout << "Enter the Name of the Movie: " << endl;
    cin >> Movie_Name;

    cout << "Enter the Price of Adult's Ticket: " << endl;
    cin >> Adult_Ticket_Price;

    cout << "Enter the Price of Child's Ticket: " << endl;
    cin >> Child_Ticket_Price;

    cout << "Enter the Number of Adult Tickets sold: " << endl;
    cin >> Number_Of_Adult_Ticket_Sold;

    cout << "Enter the Number of Child Tickets sold: " << endl;
    cin >> Number_Of_Child_Ticket_Sold;

    cout << "Enter the Percentage of Gross Ammount to be donated: " << endl;
    cin >> Percentage_To_Be_Donated;

    float Gross_Ammount = (Adult_Ticket_Price * Number_Of_Adult_Ticket_Sold) + (Child_Ticket_Price * Number_Of_Child_Ticket_Sold);
    float Ammount_To_Be_Donated = Gross_Ammount * (Percentage_To_Be_Donated/100);

    cout << "\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "Movie Name:..................................." << Movie_Name << endl;
    cout << "Number of Tickets Sold:......................." << Number_Of_Adult_Ticket_Sold + Number_Of_Child_Ticket_Sold << endl;
    cout << "Gross Ammount:................................$" << Gross_Ammount << endl;
    cout << "Percentage of Gross Ammount to be Donated:...." << Percentage_To_Be_Donated << "%" << endl;
    cout << "Ammount Donated:..............................$" << Ammount_To_Be_Donated << "\n";
    cout << "Net Sale:.....................................$" << Gross_Ammount - Ammount_To_Be_Donated << endl;
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";

    return 0;
}