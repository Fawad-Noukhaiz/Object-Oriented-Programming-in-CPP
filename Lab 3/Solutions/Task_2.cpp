/*Task - 02: Create a class called Date that includes three pieces of information as instance variables—a month (typeint), a day (typeint) and a year (typeint). Provide a method displayDate that displays the month, day and year separated by forward slashes(/). Write a test application named DateTest that demonstrates classDate’s capabilities.*/

#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

typedef class Date{
    private:

    int Day;
    int Month;
    int Year;

    public:

    void Display_Date(){
        cout << Day << "/" << Month << "/" << Year;
        return;
    }

    void Set_date(int Day, int Month, int Year){
        this -> Day = Day;
        this -> Month = Month;
        this -> Year = Year;
    }

}Date;

int main(int argc, char* argv[]){

    if(argc == 4){

        Date d1;

        d1.Set_date(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
        d1.Display_Date();

    } else {
        return 1;
    }

    return 0;
}