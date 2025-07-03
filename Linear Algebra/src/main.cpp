#include <matrix.h>
#include <iostream>

int main()
{
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
    Matrix m2 = Matrix(matrix1);
    std::cout << m2 << std::endl;
    return 0;
}