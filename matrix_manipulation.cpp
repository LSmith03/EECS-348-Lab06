/*
Program Name: EECS 348 Lab 06
Purpose: The purpose of this lab is to get framiliar with the differences between C and C++ (specifically with file IO)
Author: Logan Alexander Smith
KUID: 3096504
Due Date: 10/21/2023
Lab: lab06
Last modified: 10/21/2023
Inputs: A file containing the size of two square matricies and their corresponding values
Outputs: The values of the matricies printed followed by the sum, the product, and difference of the two matricies.
Sources: None Used
*/

#include <iostream>
#include <fstream>

void print_matrix(int** matrix, int n) {
    /*Formats and prints a matrix*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " "; // Prints each element of the matrix
        }
        std::cout << std::endl; // Jumps to next line after printing each column
    }
}

int** matrix_addition(int** matrix1, int** matrix2, int n) {
    /*Returns the sum of two matrices*/
    int** matrix_sum = new int*[n]; // Create a pointer for the sum matrix
    for (int i = 0; i < n; i++) {
        matrix_sum[i] = new int[n]; // Define the 2D array (to make a matrix)
        for(int j = 0; j < n; j++) {
            matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j]; // Sums the corresponding elements and appends
        }
    }
    return matrix_sum;
}

int** matrix_multiplication(int** matrix1, int** matrix2, int n) {
    /*Returns the product of two matrices*/
    int** matrix_product = new int*[n]; // Create a pointer for the product matrix
    for (int i = 0; i < n; i++) {
        matrix_product[i] = new int[n]; // Define the 2D array (to make a matrix)
        for (int j = 0; j < n; j++) {
            matrix_product[i][j] = 0; // Set each element to 0
            for (int k = 0; k < n; k++) {
                matrix_product[i][j] += matrix1[i][k] * matrix2[k][j]; // Multiplies the elements and adds it to the corresponding matrix_product element, then appends
            }
        }
    }
    return matrix_product;
}

int** matrix_subtraction(int** matrix1, int** matrix2, int n) {
    /*Returns the difference of two matrices*/
    int** matrix_difference = new int*[n]; // Create a pointer for the difference matrix
    for (int i = 0; i < n; i++) {
        matrix_difference[i] = new int[n]; // Define the 2D array (to make a matrix)
        for (int j = 0; j < n; j++) {
            matrix_difference[i][j] = matrix1[i][j] - matrix2[i][j]; // Subtracts the corresponding elements and appends
        }
    }
    return matrix_difference;
}

int main() {
    std::ifstream input("matrix_input.txt"); // Takes in the file
    if (!input.is_open()) {
        std::cout << "Error opening file" << std::endl; // Any problem with the file prints this message
        return 1;
    }

    int n;
    input >> n;

// Create pointers for both matrices (defined as an array)
    int** matrixA = new int*[n];
    int** matrixB = new int*[n];

// Convert the arrays to 2D-arrays (creating a matrix)
    for(int i; i < n; i++) {
        matrixA[i] = new int[n];
        matrixB[i] = new int[n];
    }

// Add the first 9 terms of the file to make Matrix A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> matrixA[i][j]; // 'Input stream' holds 9 with the next >> yielding 2
        }
    }

// Add the next 9 terms of the file to make Matrix B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> matrixB[i][j];
        }
    }

// Function calls and Print Outputs
    std::cout << "Logan Smith\n\n";
    std::cout << "Lab #6: Matrix manipulation\n\n";

    std::cout << "Matrix A:\n";
    print_matrix(matrixA, n);

    std::cout << "\nMatrix B:\n";
    print_matrix(matrixB, n);

    std::cout << "\nMatrix Sum (A + B):\n";
    print_matrix(matrix_addition(matrixA, matrixB, n), n);

    std::cout << "\nMatrix Product (A x B):\n";
    print_matrix(matrix_multiplication(matrixA, matrixB, n), n);

    std::cout << "\nMatrix Difference (A - B):\n";
    print_matrix(matrix_subtraction(matrixA, matrixB, n), n);

    return 0;
}