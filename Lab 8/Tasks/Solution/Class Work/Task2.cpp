#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PolynomialUtils;

class Polynomial {
private:
    vector<int> coefficients;
    
    void trim() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }
    
public:
    friend class PolynomialUtils;
    
    Polynomial() {}
    
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }
    
    Polynomial operator+(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] += coefficients[i];
        }
        
        for (size_t i = 0; i < other.coefficients.size(); i++) {
            result[i] += other.coefficients[i];
        }
        
        return Polynomial(result);
    }
    
    Polynomial operator-(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        
        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] += coefficients[i];
        }
        
        for (size_t i = 0; i < other.coefficients.size(); i++) {
            result[i] -= other.coefficients[i];
        }
        
        return Polynomial(result);
    }
    

    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);
        
        for (size_t i = 0; i < coefficients.size(); i++) {
            for (size_t j = 0; j < other.coefficients.size(); j++) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        
        return Polynomial(result);
    }
    
    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }
        
        bool first = true;
        for (int i = p.coefficients.size() - 1; i >= 0; i--) {
            if (p.coefficients[i] != 0) {
                if (!first) {
                    os << (p.coefficients[i] > 0 ? " + " : " - ");
                } else if (p.coefficients[i] < 0) {
                    os << "-";
                }
                
                if (abs(p.coefficients[i]) != 1 || i == 0) {
                    os << abs(p.coefficients[i]);
                }
                
                if (i > 0) {
                    os << "x";
                    if (i > 1) {
                        os << "^" << i;
                    }
                }
                first = false;
            }
        }
        return os;
    }
};

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        int power = 1;
        
        for (int coeff : p.coefficients) {
            result += coeff * power;
            power *= x;
        }
        
        return result;
    }
    
    static Polynomial derivative(const Polynomial& p) {
        if (p.coefficients.size() <= 1) {
            return Polynomial();
        }
        
        vector<int> derivCoeffs(p.coefficients.size() - 1);
        
        for (size_t i = 1; i < p.coefficients.size(); i++) {
            derivCoeffs[i - 1] = p.coefficients[i] * i;
        }
        
        return Polynomial(derivCoeffs);
    }
};

int main() {
    Polynomial p1({3, 2, 1});
    Polynomial p2({-1, 0, 4});
    
    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;
    Polynomial deriv = PolynomialUtils::derivative(p1);
    
    cout << "p1: " << p1 << "\n";
    cout << "p2: " << p2 << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Difference: " << diff << "\n";
    cout << "Product: " << prod << "\n";
    cout << "Derivative of p1: " << deriv << "\n";
    cout << "p1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << "\n";
    
    return 0;
}
