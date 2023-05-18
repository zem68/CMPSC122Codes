// Zach Mello
// 4/7/22
// Program reads an adjacency matrix, M, (which will be square) from a file, and computes powers of M : Mp, where p varies from 1 to 5 and leaves the output in a file

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX = 6; // Maximum size of array

void output(int[MAX][MAX], int, ofstream&);

int main()
{
    int row, column; // User input, number of rows and columns
    int input; // Temporary value for input
    int matrixp1[MAX][MAX] = {}; // User input, matrix M of power 1
    int matrixp2[MAX][MAX] = {}; // User input, matrix M of power 2
    int matrixp3[MAX][MAX] = {}; // User input, matrix M of power 3
    int matrixp4[MAX][MAX] = {}; // User input, matrix M of power 4
    int matrixp5[MAX][MAX] = {}; // User input, matrix M of power 5
    
    string fileName; // String name of input file
    ifstream is;
    cout << "Enter name of input file: ";
    cin >> fileName;
    is.open(fileName);

    is >> row >> column;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            is >> input;
            matrixp1[i][j] = input;
        }
    }
    is.close();

    ofstream os;
    os.open("As12output.txt");

    // M^2 = M^1 * M
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            for (int k = 0; k < column; k++) {
                matrixp2[i][j] += (matrixp1[i][k] * matrixp1[k][j]);
            }
        }
    }
    // M^3 = M^2 * M
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            for (int k = 0; k < column; k++) {
                matrixp3[i][j] += (matrixp2[i][k] * matrixp1[k][j]);
            }
        }
    }
    // M^4 = M^3 * M
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            for (int k = 0; k < column; k++) {
                matrixp4[i][j] += (matrixp3[i][k] * matrixp1[k][j]);
            }
        }
    }
    // M^5 = M^4 * M
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            for (int k = 0; k < column; k++) {
                matrixp5[i][j] += (matrixp4[i][k] * matrixp1[k][j]);
            }
        }
    }

    os << "Matrix to the power = 1" << endl;
    output(matrixp1, row, os);
    os << "Matrix to the power = 2" << endl;
    output(matrixp2, row, os);
    os << "Matrix to the power = 3" << endl;
    output(matrixp3, row, os);
    os << "Matrix to the power = 4" << endl;
    output(matrixp4, row, os);
    os << "Matrix to the power = 5" << endl;
    output(matrixp5, row, os);
    cout << "Name of output file: As12output.txt" << endl;
}

// Function will output the passed matrix
void output(int matrix[MAX][MAX], // Matrix to be outputted
    int size, // Represents both number of rows and columns, will be same because all matrices must be squares
    ofstream& os) // Reference to output file
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            os << setw(10) << setprecision(3) << matrix[i][j];
        }
        os << endl;
    }
    os << endl;
}