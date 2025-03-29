#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

class Fraction{
    private:
        int neumenator;
        int denominator;

    public:
        Fraction(int neumenator, int denominator){
            if (denominator<0)
            {
                neumenator = -neumenator;
                denominator = abs(denominator);
            }
            
            this->neumenator = neumenator;
            this->denominator = denominator;
        }

        void ReduceFraction(){
            for (int i = max(neumenator,denominator) ; i > 1 ; i--)
            {
                if (neumenator%i==0 && denominator%i==0)
                {
                    neumenator /= i;
                    denominator /= i;
                }
                
            }
            return;
        }

        void Show(){
            cout << "Neumenator: " << neumenator << endl << "Denominator: " << denominator << endl;
            return;
        }

        Fraction operator+(const Fraction& obj){
            int LCM;
            int MAX = max(denominator,obj.denominator);
            while (true)
            {
                if(MAX%denominator==0 && MAX%obj.denominator==0){
                    LCM = MAX;
                    break;
                } else {
                    MAX++;
                }
            }
            int m1 = LCM/denominator;
            int m2 = LCM/obj.denominator;

            neumenator *= m1;
            denominator *= m1;

            int a = obj.neumenator * m2;
            int b = obj.denominator * m2;

            return Fraction(neumenator+a,LCM);
        }

        Fraction operator-(const Fraction& obj){
            int LCM;
            int MAX = max(denominator,obj.denominator);
            while (true)
            {
                if(MAX%denominator==0 && MAX%obj.denominator==0){
                    LCM = MAX;
                    break;
                } else {
                    MAX++;
                }
            }
            int m1 = LCM/denominator;
            int m2 = LCM/obj.denominator;

            neumenator *= m1;
            denominator *= m1;

            int a = obj.neumenator * m2;
            int b = obj.denominator * m2;

            return Fraction(neumenator-a,LCM);
        }

        Fraction operator*(const Fraction& obj){
            return Fraction(neumenator*obj.neumenator,denominator*obj.denominator);
        }

        Fraction operator/(const Fraction& obj){
            return Fraction(neumenator*obj.denominator,denominator*obj.neumenator);
        }


};

int main(){

    Fraction a(2,4);
    a.Show();
    a.ReduceFraction();
    a.Show();
    Fraction b(3,7);

    Fraction C = a + b;

    C.Show();

    return 0;
}