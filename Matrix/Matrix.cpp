#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int** g(const int cols, const int rows)
{
    int** matrix = new int* [cols] {};
    matrix[0] = new int[rows*cols];
    for (int i = 1; i < rows; i++) {
        matrix[i] = matrix[i - 1] + cols;
    }
    return matrix;
}

void fill(int** matrix, const int cols, const int rows)
{
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j = rows; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print(const int cols, const int rows, int* matrix[])
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

void memory_clear(int* matrix[])
{
    delete[] matrix[0];
    delete[] matrix;
}