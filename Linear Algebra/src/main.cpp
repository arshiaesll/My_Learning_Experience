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
    // int a = 2;
    // std::cout << f(a) << std::endl;
    // Person p1 = Person(1, 2);
    // p1.print();

    // Person p2 = Person(3, 4);
    // p2.print();
    // p1 = p2;
    // p1.print();

    int rows = 3, cols = 10;
    Matrix matrix1 = Matrix(rows, cols);

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            // Works
            // matrix1.matrix[i][j] = i * j;
            // Doesn't work

            matrix1[i][j] = i * j;
        }
    }
    std::cout << matrix1 << std::endl;
    Matrix m2 = matrix1.transpose();
    std::cout << m2 << std::endl;
    std::cout << m2.transpose() << std::endl;
    // std::cout << matrix1.toString() << std::endl;

    return 0;
}