// Zach Mello
// 3/31/22
// Program reads 2 matrices and adds them (if compatible) and prints their sum, subtracts them(if compatible) and prints their difference, and multiplies them(if compatible) and prints their product

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX = 6;

int main()
{
    int row1, row2; // User input, row size for matrix 1 and 2, respectively
    int column1, column2; // User input, column size for matrix 1 and 2, respectively
    double matrix1[MAX][MAX]; // User input, matrix #1
    double matrix2[MAX][MAX]; // User input, matrix #2
    double matrixAdd[MAX][MAX]; // User output, Result of matrix addition
    double matrixSub[MAX][MAX]; // User output, Result of matrix subtraction
    double matrixMult[MAX][MAX] = {}; // User output, Result of matrix multiplication
    double input; // Temporary value for input file values

    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of 1st input file: ";
    cin >> fileName;
    is.open(fileName);

    is >> row1 >> column1;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column1; j++) {
            is >> input;
            matrix1[i][j] = input;
        }
    }
    is.close();

    cout << "Enter name of 2nd input file: ";
    cin >> fileName;
    is.open(fileName);

    is >> row2 >> column2;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < column2; j++) {
            is >> input;
            matrix2[i][j] = input;
        }
    }
    is.close();

    ofstream os;
    cout << "Enter name of output file: ";
    cin >> fileName;
    os.open(fileName);

    os << fixed << right;
    os << "Matrix A =" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < column1; j++) {
            os << setw(10) << setprecision(3) << matrix1[i][j];
        }
        os << endl;
    }
    os << endl;
    os << "Matrix B =" << endl;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < column2; j++) {
            os << setw(10) << setprecision(3) << matrix2[i][j];
        }
        os << endl;
    }
    os << endl;
    if ((row1 == row2) && (column1 == column2)) {
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                matrixAdd[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                matrixSub[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        os << "A + B =" << endl;
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                os << setw(10) << setprecision(3) << matrixAdd[i][j];
            }
            os << endl;
        }
        os << endl;
        os << "A - B =" << endl;
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column1; j++) {
                os << setw(10) << setprecision(3) << matrixSub[i][j];
            }
            os << endl;
        }
        os << endl;
    }
    else {
        os << "Cannot do matrix addition" << endl;
        os << endl;
        os << "Cannot do matrix subtraction" << endl;
        os << endl;
    }

    if (column1 == row2) {
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column2; j++) {
                for (int k = 0; k < column1; k++) {
                    matrixMult[i][j] += (matrix1[i][k] * matrix2[k][j]);
                }
            }
        }
        os << "A * B =" << endl;
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < column2; j++) {
                os << setw(10) << setprecision(3) << matrixMult[i][j];
            }
            os << endl;
        }
        os << endl;
    }
    else {
        os << "Cannot do matrix multiplication" << endl;
    }
}

