#include<bits/stdc++.h>
using namespace std;

class Shape{
    protected:
        int x,y;
        string Color;

    public:
        virtual void draw() = 0;
        virtual int CalculateArea() = 0;
        virtual int CalculatePerimeter() = 0;

        void GetInfo(){
            cout << "Position: " << x << ", " << y << endl;
            cout << "Color: " << Color << endl;
        }
};

class Circle : protected Shape{
    private:
        int radius;

    public:
        Circle(int x, int y, int radius, string color){
            this->x = x;
            this->y = y;
            this->radius = radius;
            this->Color = color;
        }

        void draw() override{
            cout << "Drawing a Circle at (" << x << ", " << y << ") with radius " << radius << " and color " << Color << "\n";
        }

        int CalculateArea() override {
            return 3.14*radius*radius;
        }

        int CalculatePerimeter() override {
            return 2*3.14*radius;
        }
};

class Triangle : protected Shape{
    protected:
        int SideA,SideB,SideC;

    public:
        Triangle(int x, int y, int SideA, int SideB, int SideC, string Color){
            this->x = x;
            this->y = y;
            this->SideA = SideA;
            this->SideB = SideB;
            this->SideC = SideC;
            this->Color = Color;
        }

        void draw() override {
            cout << "Drawing a Triangle at (" << x << ", " << y << ") with Sides " << SideA << ", " << SideB << ", " << SideC << " and color " << Color << "\n";
        }

        int CalculateArea() override {
            float s = (SideA + SideB + SideC)/2;
            return sqrt(s * (s - SideA) * (s - SideB) * (s - SideC));
        }

        int CalculatePerimeter() override {
            return SideA + SideB + SideC;
        }
};

class Rectangle : protected Shape{
    protected:
        int length, width;

    public:
        Rectangle(int x, int y, int length, int width, string Color){
            this->x = x;
            this->y = y;
            this->length = length;
            this->width = width;
            this->Color = Color;
        }

        void draw() override {
            cout << "Drawing a Rectangle at (" << x << ", " << y << ") with Length " << length << " and Width" << width << " and color " << Color << "\n";
        }

        int CalculateArea(){
            return width*length;
        }

        int CalculatePerimeter(){
            return (2*length)+(2*width);
        }
};

int main(){

    Circle circle(5, 5, 10, "Red");
    Rectangle rectangle(2, 3, 8, 6, "Blue");
    Triangle triangle(1, 1, 5, 6, 7, "Green");

    circle.draw();
    rectangle.draw();
    triangle.draw();

    cout << "\n--- Shape Calculations ---\n";

    cout << "Circle Area: " << circle.CalculateArea() << ", Perimeter: " << circle.CalculatePerimeter() << "\n";
    cout << "Rectangle Area: " << rectangle.CalculateArea() << ", Perimeter: " << rectangle.CalculatePerimeter() << "\n";
    cout << "Triangle Area: " << triangle.CalculateArea() << ", Perimeter: " << triangle.CalculatePerimeter() << "\n";

    return 0;
}