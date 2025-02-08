/*Task - 01: Create a class User with two public fields: int Age and string Name. In the Main method, create an object of class User and set Name to "Teo" and Age to 24. Then, output to the screen: "My name is {Name} and I'm {Age} years old." using object fields for Name and Age.*/

#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class User{
    public:
    string Name;
    int Age;
};

int main(int argc, char* argv[]){

    if (argc == 3)
    {
        User User1;

        User1.Name = argv[1];
        User1.Age = atoi(argv[2]);

        cout << "My name is " << User1.Name << " and I'm " << User1.Age << " Years Old";
    }

    else{
        return 1;
    }
    

    return 0;
}