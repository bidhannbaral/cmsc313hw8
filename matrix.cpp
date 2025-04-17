#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    public:

    int** m_matrix;
    int m_rows, m_columns;

    Matrix(int rows, int columns) {

        if (rows <= 0 || columns <= 0) {
            throw invalid_argument("Matrix dimensions must be positive");
        }

        m_rows = rows;
        m_columns = columns;
        m_matrix = new int*[m_rows];
        for (int i = 0; i < m_rows; i++) {
            m_matrix[i] = new int[m_columns];
            for (int j = 0; j < m_columns; j++)
                m_matrix[i][j] = 0;
        }
    }

    ~Matrix() {
        for (int i = 0; i < m_rows; i++)
            delete[] m_matrix[i];
        delete[] m_matrix;
    }

    void print() {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_columns; j++)
                cout << m_matrix[i][j] << " ";
            cout << endl;
        }
    }

    Matrix add(Matrix other) {
        if (m_rows != other.m_rows || m_columns != other.m_columns) {
            throw invalid_argument("Matrix sizes don't match for addition");
        }

        Matrix result(m_rows, m_columns);
        for (int i = 0; i < m_rows; i++)
            for (int j = 0; j < m_columns; j++)
                result.m_matrix[i][j] = m_matrix[i][j] + other.m_matrix[i][j];
        return result;
    }

    Matrix scalarMultiply(int num) {
        Matrix result(m_rows, m_columns);
        for (int i = 0; i < m_rows; i++)
            for (int j = 0; j < m_columns; j++)
                result.m_matrix[i][j] = m_matrix[i][j] * num;
        return result;
    }

    Matrix transpose() {
        Matrix result(m_columns, m_rows);
        for (int i = 0; i < m_rows; i++)
            for (int j = 0; j < m_columns; j++)
                result.m_matrix[j][i] = m_matrix[i][j];
        return result;
    }

    Matrix matrixMultiply(Matrix other) {

        if (m_columns != other.m_rows) {
            throw invalid_argument("Matrix multiplication requires the first matrix's columns to equal the second matrix's rows");
        }

        Matrix result(m_rows, other.m_columns);
        for (int i = 0; i < m_rows; i++)
            for (int j = 0; j < other.m_columns; j++)
                for (int k = 0; k < m_columns; k++)
                    result.m_matrix[i][j] += m_matrix[i][k] * other.m_matrix[k][j];
        return result;
    }
};

int main() {

    Matrix A(2, 2);
    A.m_matrix[0][0] = 6; 
    A.m_matrix[0][1] = 4;
    A.m_matrix[1][0] = 8; 
    A.m_matrix[1][1] = 3;

    Matrix B(2, 3);
    B.m_matrix[0][0] = 1; 
    B.m_matrix[0][1] = 2; 
    B.m_matrix[0][2] = 3;
    B.m_matrix[1][0] = 4; 
    B.m_matrix[1][1] = 5; 
    B.m_matrix[1][2] = 6;

    Matrix C(2, 3);
    C.m_matrix[0][0] = 2; 
    C.m_matrix[0][1] = 4; 
    C.m_matrix[0][2] = 6;
    C.m_matrix[1][0] = 1; 
    C.m_matrix[1][1] = 3; 
    C.m_matrix[1][2] = 5;

    Matrix B3 = B.scalarMultiply(3);
    Matrix Ct = C.transpose();
    Matrix B3Ct = B3.matrixMultiply(Ct);
    Matrix D = A.add(B3Ct);

    cout << "Matrix D:" << endl;
    D.print();

    return 0;
}