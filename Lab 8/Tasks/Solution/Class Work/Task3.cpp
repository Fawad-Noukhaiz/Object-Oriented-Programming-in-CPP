#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

    void trim() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

public:
    BigInteger() : isNegative(false) {}

    BigInteger(string str) {
        if (str.empty()) {
            *this = BigInteger();
            return;
        }
        isNegative = (str[0] == '-');
        for (int i = str.size() - 1; i >= (isNegative ? 1 : 0); --i) {
            digits.push_back(str[i] - '0');
        }
        trim();
    }

    BigInteger operator+(const BigInteger &other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            int carry = 0, sum = 0;
            size_t maxSize = max(digits.size(), other.digits.size());

            for (size_t i = 0; i < maxSize || carry; i++) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            result.trim();
            return result;
        }
        return *this - (-other);
    }

    BigInteger operator-(const BigInteger &other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }
        if (*this < other) {
            return -(other - *this);
        }

        BigInteger result;
        result.isNegative = isNegative;
        int borrow = 0;

        for (size_t i = 0; i < digits.size(); i++) {
            int diff = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.trim();
        return result;
    }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (result.digits.size() > 1 || result.digits[0] != 0) {
            result.isNegative = !isNegative;
        }
        return result;
    }

    bool operator==(const BigInteger &other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }

    bool operator!=(const BigInteger &other) const { return !(*this == other); }

    bool operator<(const BigInteger &other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (digits.size() != other.digits.size()) {
            return isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] != other.digits[i]) {
                return isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator>(const BigInteger &other) const { return other < *this; }
    bool operator<=(const BigInteger &other) const { return !(other < *this); }
    bool operator>=(const BigInteger &other) const { return !(*this < other); }

    friend istream &operator>>(istream &is, BigInteger &num) {
        string str;
        is >> str;
        num = BigInteger(str);
        return is;
    }

    friend ostream &operator<<(ostream &os, const BigInteger &num) {
        if (num.isNegative) {
            os << "-";
        }
        for (int i = num.digits.size() - 1; i >= 0; i--) {
            os << num.digits[i];
        }
        return os;
    }
};

int main() {
    BigInteger num1, num2;
    cout << "Enter two big integers: ";
    cin >> num1 >> num2;

    cout << "Sum: " << (num1 + num2) << "\n";
    cout << "Difference: " << (num1 - num2) << "\n";
    cout << "Comparison: " << (num1 < num2 ? "num1 < num2" : "num1 >= num2") << "\n";
    
    return 0;
}
