#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimensions do not match";
    }
};

template<typename T>
class Matrix {
    vector<vector<T>> mat;
    size_t rows, cols;
public:
    Matrix(size_t r, size_t c) : rows(r), cols(c), mat(r, vector<T>(c)) {}

    T& at(size_t i, size_t j) {
        if (i >= rows || j >= cols)
            throw out_of_range("Matrix index out of range");
        return mat[i][j];
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols != other.rows)
            throw DimensionMismatchException();
        Matrix<T> result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j)
                for (size_t k = 0; k < cols; ++k)
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
        return result;
    }
};

int main() {
    Matrix<int> m1(2, 2), m2(2, 2);
    m1.at(0, 0) = 1; m1.at(0, 1) = 2;
    m1.at(1, 0) = 3; m1.at(1, 1) = 4;
    m2.at(0, 0) = 5; m2.at(0, 1) = 6;
    m2.at(1, 0) = 7; m2.at(1, 1) = 8;
    try {
        Matrix<int> sum = m1 + m2;
        cout << sum.at(0, 0) << " " << sum.at(0, 1) << endl;
        cout << sum.at(1, 0) << " " << sum.at(1, 1) << endl;
        Matrix<int> product = m1 * m2;
        cout << product.at(0, 0) << " " << product.at(0, 1) << endl;
        cout << product.at(1, 0) << " " << product.at(1, 1) << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
