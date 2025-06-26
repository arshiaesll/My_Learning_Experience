#include <matrix.h>
#include <iostream>

int main()
{
    int rows = 3, cols = 10;
    Matrix matrix = Matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = i * j;
        }
    }
    std::cout << matrix;
    return 0;
}