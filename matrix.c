#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** m_data;
    int m_rows;
    int m_columns;
} Matrix;

Matrix createMatrix(int rows, int columns) {
    Matrix one;
    one.m_rows = rows;
    one.m_columns = columns;
    one.m_data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        one.m_data[i] = (int*)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++)
            one.m_data[i][j] = 0;
    }
    return one;
}

void freeMatrix(Matrix* one) {
    for (int i = 0; i < one->m_rows; i++)
        free(one->m_data[i]);
    free(one->m_data);
}

void printMatrix(Matrix one) {
    for (int i = 0; i < one.m_rows; i++) {
        for (int j = 0; j < one.m_columns; j++)
            printf("%d ", one.m_data[i][j]);
        printf("\n");
    }
}

Matrix add(Matrix one, Matrix two) {
    Matrix result = createMatrix(one.m_rows, one.m_columns);
    for (int i = 0; i < one.m_rows; i++)
        for (int j = 0; j < one.m_columns; j++)
            result.m_data[i][j] = one.m_data[i][j] + two.m_data[i][j];
    return result;
}

Matrix scalarMultiply(Matrix one, int num) {
    Matrix result = createMatrix(one.m_rows, one.m_columns);
    for (int i = 0; i < one.m_rows; i++)
        for (int j = 0; j < one.m_columns; j++)
            result.m_data[i][j] = one.m_data[i][j] * num;
    return result;
}

Matrix transpose(Matrix one) {
    Matrix result = createMatrix(one.m_columns, one.m_rows);
    for (int i = 0; i < one.m_rows; i++)
        for (int j = 0; j < one.m_columns; j++)
            result.m_data[j][i] = one.m_data[i][j];
    return result;
}

Matrix matrixMultiply(Matrix one, Matrix two) {
    Matrix result = createMatrix(one.m_rows, two.m_columns);
    for (int i = 0; i < one.m_rows; i++)
        for (int j = 0; j < two.m_columns; j++)
            for (int k = 0; k < one.m_columns; k++)
                result.m_data[i][j] += one.m_data[i][k] * two.m_data[k][j];
    return result;
}

int main() {
    Matrix A = createMatrix(2, 2);
    A.m_data[0][0] = 6; 
    A.m_data[0][1] = 4;
    A.m_data[1][0] = 8; 
    A.m_data[1][1] = 3;

    Matrix B = createMatrix(2, 3);
    B.m_data[0][0] = 1; 
    B.m_data[0][1] = 2; 
    B.m_data[0][2] = 3;
    B.m_data[1][0] = 4; 
    B.m_data[1][1] = 5; 
    B.m_data[1][2] = 6;

    Matrix C = createMatrix(2, 3);
    C.m_data[0][0] = 2; 
    C.m_data[0][1] = 4; 
    C.m_data[0][2] = 6;
    C.m_data[1][0] = 1; 
    C.m_data[1][1] = 3; 
    C.m_data[1][2] = 5;

    Matrix B3 = scalarMultiply(B, 3);
    Matrix Ct = transpose(C);
    Matrix B3Ct = matrixMultiply(B3, Ct);
    Matrix D = add(A, B3Ct);

    printf("Matrix D:\n");
    printMatrix(D);

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&B3);
    freeMatrix(&Ct);
    freeMatrix(&B3Ct);
    freeMatrix(&D);

    return 0;
}