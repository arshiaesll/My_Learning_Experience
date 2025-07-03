

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

class Matrix
{

public:
    Matrix(int rows, int cols);
    Matrix(const Matrix &matrix);
    // The number of rows
    int rows;
    // The number of columns
    int cols;
    // The rank of the matrix
    int rank;
    std::vector<std::vector<double>> matrix;

    double operator()(int i, int j) const { return matrix[i][j]; }
    std::vector<double> operator[](int i) { return matrix[i]; }
    // void operator=(int i) {}
    std::string toString() const;
    // Transpose the matrix and return the new Transposed matrix
    Matrix T();

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
};

#endif // MATRIX_H