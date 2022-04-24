#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Header_Matrix.h"

using namespace std;

void f()
{
    int* a = new int[100'000];
    for (int i = 0; i < 100'000; i++) {
        a[i] = rand() % 1000;
    }

    sort(a, a + 100'000);
    delete[] a;
}


int main()
{
    srand(time(0));
    const int cols = 4;
    const int rows = 4;
    int** matrix = g(rows, cols);
    fill(matrix, rows, cols);
    print(cols, rows, matrix);
    memory_clear(matrix);
}

