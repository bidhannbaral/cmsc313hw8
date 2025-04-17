#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** m_matrix;
    int m_rows;
    int m_columns;
} Matrix;

Matrix createMatrix(int rows, int columns) {
    
    Matrix one;
    if (rows <= 0 || columns <= 0) {
        fprintf(stderr, "Matrix dimensions must be positive\n");
        one.m_rows = one.m_columns = 0;
        one.m_matrix = NULL;
        return one;
    }

    one.m_rows = rows;
    one.m_columns = columns;
    one.m_matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        one.m_matrix[i] = (int*)malloc(columns * sizeof(int));
        for (int j = 0; j < columns; j++)
            one.m_matrix[i][j] = 0;
    }
    return one;
}

void freeMatrix(Matrix* one) {

    if (one->m_matrix == NULL) {
        return;
    }

    for (int i = 0; i < one->m_rows; i++)
        free(one->m_matrix[i]);
    free(one->m_matrix);
    one->m_matrix = NULL;
    one->m_rows = one->m_columns = 0;
}

void printMatrix(Matrix one) {

    for (int i = 0; i < one.m_rows; i++) {
        for (int j = 0; j < one.m_columns; j++)
            printf("%d ", one.m_matrix[i][j]);
        printf("\n");
    }
}

Matrix add(Matrix one, Matrix two) {

    if (one.m_rows != two.m_rows || one.m_columns != two.m_columns) {
        fprintf(stderr, "Matrix sizes don't match for addition\n");
        return createMatrix(0, 0);
    }

    Matrix result = createMatrix(one.m_rows, one.m_columns);
    for (int i = 0; i < one.m_rows; i++)
        for (int j = 0; j < one.m_columns; j++)
            result.m_matrix[i][j] = one.m_matrix[i][j] + two.m_matrix[i][j];
    return result;
}

Matrix scalarMultiply(Matrix one, int num) {

    Matrix result = createMatrix(one.m_rows, one.m_columns);
    for (int i = 0; i < one.m_rows; i++)
        for (int j = 0; j < one.m_columns; j++)
            result.m_matrix[i][j] = one.m_matrix[i][j] * num;
    return result;
}

Matrix transpose(Matrix one) {

    Matrix result = createMatrix(one.m_columns, one.m_rows);
    for (int i = 0; i < one.m_rows; i++)
        for (int j = 0; j < one.m_columns; j++)
            result.m_matrix[j][i] = one.m_matrix[i][j];
    return result;
}

Matrix matrixMultiply(Matrix one, Matrix two) {

    if (one.m_columns != two.m_rows) {
        fprintf(stderr, "Matrix multiplication requires the first matrix's columns to equal the second matrix's rows\n");
        return createMatrix(0, 0);
    }

    Matrix result = createMatrix(one.m_rows, two.m_columns);
    for (int i = 0; i < one.m_rows; i++)
        for (int j = 0; j < two.m_columns; j++)
            for (int k = 0; k < one.m_columns; k++)
                result.m_matrix[i][j] += one.m_matrix[i][k] * two.m_matrix[k][j];
    return result;
}

int main() {
    Matrix A = createMatrix(2, 2);
    A.m_matrix[0][0] = 6; 
    A.m_matrix[0][1] = 4;
    A.m_matrix[1][0] = 8; 
    A.m_matrix[1][1] = 3;

    Matrix B = createMatrix(2, 3);
    B.m_matrix[0][0] = 1; 
    B.m_matrix[0][1] = 2; 
    B.m_matrix[0][2] = 3;
    B.m_matrix[1][0] = 4; 
    B.m_matrix[1][1] = 5; 
    B.m_matrix[1][2] = 6;

    Matrix C = createMatrix(2, 3);
    C.m_matrix[0][0] = 2; 
    C.m_matrix[0][1] = 4; 
    C.m_matrix[0][2] = 6;
    C.m_matrix[1][0] = 1; 
    C.m_matrix[1][1] = 3; 
    C.m_matrix[1][2] = 5;

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
