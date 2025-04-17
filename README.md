Author: 
    Bidhan Baral; student at UMBC; class: CMSC313 Monday/Wednesday from 10am - 11:15am

PURPOSE OF SOFTWARE:
    This software takes 3 matricies A, B, and C and creates a new matrix D by doing the operation: D = A + (3 * B) * C^(transpose). This will help me learn
    how to code in C. Also, the operations don't have to be in that exact order. 

FILES:
    matrix.cpp: This is the file with the code for the assignment. This file contains C++ code takes 3 matricies A, B, and C and creates a new matrix D
                by doing the operation: D = A + (3 * B) * C^(transpose).
    matrix.c: This is the file with the code for the assignment. This file condains C code and is similar to the matrix.cpp file in where it has the same
                functionality. It takes 3 matricies A, B, and C and creates a new matrix D by doing the operation: D = A + (3 * B) * C^(transpose).

BUILD INSTRUCTIONS:
    matrix.cpp: g++ -m32 -O0 matrix.cpp -o CPPmatrix
    matrix.c: gcc -std=c99 -m32 -O0 matrix.c -o Cmatrix

TESTING METHODOLOGY:
    matrix.cpp: In the terminal compile matrix.cpp and run it.
    matrix.c: In the terminal compile matrix.c and run it.

ADDITIONAL INFORMATION:
    You can change the values and dimensions of the matrix in the main function. 
    Also, you can also change the operations that you want the code to run in the main function.
