#include <matrix.h>
#include <iostream>

int f(int &a)
{
    int b = a + 1;
    return b;
}

class Person
{

public:
    Person(int num1, int num2)
    {
        a = num1;
        b = num2;
    }
    int a;
    int b;
    void print()
    {
        std::cout << a << " " << b << std::endl;
    }
};

int main()
{

    int rows = 3, cols = 10;
    Matrix matrix1 = Matrix(rows, cols);

    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Works
            // matrix1.matrix[i][j] = i * j;
            // Doesn't work

            matrix1(i, j) = ++counter;
            std::cout << counter << " ";
            std::cout << matrix1(i, j) << std::endl;
            ;
        }
    }

    std::cout << matrix1.matrix.size() << std::endl;
    std::cout << matrix1 << std::endl;
    // std::cout << matrix1.rows << " " << matrix1.cols << std::endl;
    // Matrix m2 = matrix1.transpose();
    // std::cout << m2 << std::endl;
    // std::cout << m2.transpose() << std::endl;

    return 0;
}