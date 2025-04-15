Author: 
    Bidhan Baral; student at UMBC; class: CMSC313 Monday/Wednesday from 10am - 11:15am

PURPOSE OF SOFTWARE:
    This software takes 3 matricies A, B, and C and creates a new matrix D by doing the operation: D = A + (3 * B) * C^(transpose). This will help me learn
    how to code in C.

FILES:
    matrix.cpp: This is the file with the code for the assignment. This file contains C++ code takes 3 matricies A, B, and C and creates a new matrix D
                by doing the operation: D = A + (3 * B) * C^(transpose).
    matrix.c: This is the file with the code for the assignment. This file condains C code and is similar to the matrix.cpp file in where it has the same
                functionality. It takes 3 matricies A, B, and C and creates a new matrix D by doing the operation: D = A + (3 * B) * C^(transpose).

BUILD INSTRUCTIONS:
    matrix.cpp: g++ -Wall matrix.cpp -o CPPmatrix
    matrix.c: gcc -Wall matrix.c -o Cmatrix or g++ -Wall matrix.c -o Cmatrix

TESTING METHODOLOGY:
    matrix.cpp: in the terminal after building run ./CPPmatrix 
    matrix.c: in the terminal after building run ./Cmatrix

ADDITIONAL INFORMATION:
    I have provided an image that shows how I built and tested the program named "build-test.png".
    I have also provided the .exe files after I compiled the programs(Cmatrix.exe and CPPmatrix.exe). 
