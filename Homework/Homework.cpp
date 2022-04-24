// 1. Шаблон функции свап. (использовать адресную арифметику).
// 2. Шаблон функции печати одномерного массива.


#include <iostream>
using namespace std;

template<typename T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void myprint(T &begin, const int array_size)
{
    for (int i = 0; i < array_size; i++) {
        cout << *(begin+i) << "   ";
    }
    cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a = 10;
    int b = 5;
    myswap(a, b);
    cout << " a = " << a << " b = " << b << '\n';

    const int array_size = 10;
    int digits_array[array_size] = { 1,3,5,4,6,1,0,4,9,4 };
    int* pd_a = &digits_array[0];
    myprint(pd_a, array_size);
    char char_array[array_size] = { 'a','b','c','d','e','f','g','h','i','j' };
    char* pc_a = char_array;
    myprint(pc_a, array_size);
}

