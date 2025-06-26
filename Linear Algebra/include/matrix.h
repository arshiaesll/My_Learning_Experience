

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

class Matrix
{

public:
    Matrix(int rows, int cols);
    Matrix(const Matrix &matrix);
    int rows;
    int cols;
    std::vector<std::vector<double>> matrix;

    double operator()(int i, int j) const { return matrix[i][j]; }
    std::vector<double> operator[](int i) const { return matrix[i]; }

    std::string toString() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);
};

#endif // MATRIX_H