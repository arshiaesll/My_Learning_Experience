
#include <matrix.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->matrix.resize(rows * cols);
}

// deep copy
Matrix::Matrix(const Matrix &rhsMatrix)
{
    this->rows = rhsMatrix.rows;
    this->cols = rhsMatrix.cols;
    this->matrix.resize(rows * cols, 0);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // TODO: Check if it's working
            this->matrix[getIndex(i, j)] = rhsMatrix(i, j);
        }
    }
    // this->matrix = matrix.matrix;
}

std::string Matrix::toString() const
{
    std::ostringstream oss;
    std::string result = "";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            oss << (*this)(i, j) << " ";
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
            m(i, j) = (*this)(i, j);
        }
    }
    return m;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    os << matrix.toString();
    return os;
}

double Matrix::operator()(int i, int j) const
{
    // Row major representation
    return matrix[getIndex(i, j)];
}

double &Matrix::operator()(int i, int j)
{
    return matrix[getIndex(i, j)];
}
// Row i, colum j
int Matrix::getIndex(int i, int j) const
{
    return rows * i + j;
}
// double Matrix::operator[](int)
