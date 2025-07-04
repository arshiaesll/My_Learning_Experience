
#include <matrix.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->matrix.resize(rows, std::vector<double>(cols));
    // std::cout << this->transpose() << std::endl;
}

// deep copy
Matrix::Matrix(const Matrix &matrix)
{
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->matrix.resize(rows, std::vector<double>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // TODO: Check if it's working
            this->matrix[i][j] = matrix.matrix[i][j];
        }
    }
    this->matrix = matrix.matrix;
}

std::string Matrix::toString() const
{
    std::ostringstream oss;
    std::string result = "";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            oss << matrix[i][j] << " ";
            result += oss.str();
            oss.str("");
        }
        result += "\n";
    }

    return result;
}

Matrix Matrix::transpose()
{
    Matrix m = Matrix(this->cols, this->rows);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            // TODO: This should be fixed after fixing the operator bug
            m[j][i] = (*this)[i][j];
        }
    }
    return m;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    os << matrix.toString();
    return os;
}
