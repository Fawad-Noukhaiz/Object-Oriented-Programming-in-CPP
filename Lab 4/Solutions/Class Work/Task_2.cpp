#include <iostream>
#include <math.h>
#include <stdexcept>
using namespace std;

class Polynomial {
private:
    int degree;
    double* coefficients;

public:
    Polynomial() : degree(0), coefficients(new double[1]{0}) {}

    Polynomial(int deg, const double* coeffs) : degree(deg) {
        coefficients = new double[deg + 1];
        for (int i = 0; i <= deg; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.degree = 0;
        other.coefficients = nullptr;
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    int getDegree() const { return degree; }

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* resultCoeffs = new double[maxDegree + 1]{0};

        for (int i = 0; i <= degree; ++i) resultCoeffs[i] += coefficients[i];
        for (int i = 0; i <= other.degree; ++i) resultCoeffs[i] += other.coefficients[i];

        Polynomial result(maxDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        int resultDegree = degree + other.degree;
        double* resultCoeffs = new double[resultDegree + 1]{0};

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(resultDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }

    void print() const {
        for (int i = 0; i <= degree; ++i) {
            cout << coefficients[i] << "x^" << i << " ";
        }
        cout << endl;
    }
};

int main() {
    double coeffs1[] = {1, 2, 3};
    Polynomial p1(2, coeffs1);
    p1.print();

    double coeffs2[] = {4, 5};
    Polynomial p2(1, coeffs2);
    p2.print();

    Polynomial p3 = p1.add(p2);
    p3.print();

    Polynomial p4 = p1.multiply(p2);
    p4.print();

    return 0;
}