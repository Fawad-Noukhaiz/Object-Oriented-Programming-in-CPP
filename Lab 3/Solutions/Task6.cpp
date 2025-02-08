/*Task -06:
Create a class called Matrix containing a  constructor that initializes the number of rows and number of columns of a new Matrix object. The Matrix class has the following information.
1.	Number of rows of matrix
2.	Number of columns of matrix
3.	Elements of matrix in the form of 2D array
The Matrix class has methods for each of the following
1. Get the number of rows
2. Get the number of columns
3. Set the elements of the matrix at the given position (i,j)
4. Adding two matrices. If the matrices are not addable, “Matrices cannot be added” will be displayed
5. Multiplying the two matrices
*/

#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> matrix;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        matrix.resize(rows, vector<int>(cols, 0));
    }

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            matrix[i][j] = value;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage: <program> <rows> <cols> <matrix_elements>" << endl;
        return 1;
    }

    int rows = stoi(argv[1]);
    int cols = stoi(argv[2]);

    Matrix mat(rows, cols);
    int index = 3;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat.setElement(i, j, stoi(argv[index++]));
        }
    }

    mat.display();

    return 0;
}
