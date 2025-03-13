#include "Matrix.h"
#include <iostream>



double** Matrix::createData(int rows, int cols)
{
    double** newData = new double* [rows];
    for (int i = 0; i < rows; i++) {
        newData[i] = new double[cols] {};
    return newData;
}


void Matrix::freeData(double** data, int rows)
{
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

Matrix::Matrix() : rows(0), cols(0), data(nullptr) {}

Matrix::Matrix(int dim) : rows(dim), cols(dim) {
    data = createData(rows, cols);
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data = createData(rows, cols);
}

Matrix::Matrix(const Matrix& matr) : rows(matr.rows), cols(matr.cols) {
    data = createData(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = matr.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    if (data) {
        freeData(data, rows);
    }
}

double Matrix::get(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[row][col];
}

void Matrix::set(int row, int col, double val) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    data[row][col] = val;
}

int Matrix::getR() {
    return rows;
}

int Matrix::getC() {
    return cols;
}

void Matrix::print(std::ostream& stream) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            stream << std::setw(8) << data[i][j] << " ";
        }
        stream << std::endl;
    }
}


void Matrix::multBy(double k) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] *= k;
        }
    }
}

void Matrix::transpose() {
    double** transposed = createData(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = data[i][j];
        }
    }
    freeData(data, rows);
    data = transposed;
    std::swap(rows, cols);
}