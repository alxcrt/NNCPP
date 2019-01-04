#include "Matrix.h"
#include <math.h>
#include <ctime>
#include <iostream>
#include <vector>

// Constructor
Matrix::Matrix(int rows_, int cols_) {
  rows = rows_;
  cols = cols_;
  randomize(rows, cols);
}

Matrix::Matrix() {}

Matrix Matrix::operator+(Matrix x) {
  if (x.rows != rows || x.cols != cols) {
    std::cout << "Matrix+ : rows and Cols are not the same\n";
    return x;  // FIXME: Find a better way to return
  } else {
    Matrix newMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        newMatrix.M[i][j] = M[i][j] + x.M[i][j];
      }
    }
    return newMatrix;
  }
}

Matrix Matrix::operator-(Matrix x) {
  if (x.rows != rows || x.cols != cols) {
    std::cout << "Matrix+ : rows and Cols are not the same\n";
    return x;  // FIXME: Find a better way to return
  } else {
    Matrix newMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        newMatrix.M[i][j] = M[i][j] - x.M[i][j];
      }
    }
    return newMatrix;
  }
}

Matrix Matrix::operator*(Matrix x) {
  if (x.rows != rows || x.cols != cols) {
    std::cout << "Matrix * Matrix : rows and Cols are not the same\n";
    return x;  // FIXME: Find a better way to return
  } else {
    Matrix newMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < x.cols; j++) {
        newMatrix.M[i][j] = M[i][j] * x.M[i][j];
      }
    }
    return newMatrix;
  }
}

Matrix Matrix::operator*(double x) {
  Matrix newMatrix(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      newMatrix.M[i][j] = M[i][j] * x;
    }
  }
  return newMatrix;
}

Matrix Matrix::dot(Matrix x) {
  if (cols != x.rows) {
    std::cout
        << "Matrix dot : Matrix1 cols and Matrix2 rows are not the same\n";
    return x;  // FIXME: Find a better way to return
  } else {
    Matrix newMatrix(rows, x.cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < x.cols; j++) {
        double S = 0;
        for (int k = 0; k < cols; k++) {
          S += M[i][k] * x.M[k][j];
        }
        newMatrix.M[i][j] = S;
      }
    }
    return newMatrix;
  }
}

Matrix Matrix::transpose() {
  Matrix newMatrix(cols, rows);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      newMatrix.M[j][i] = M[i][j];
    }
  }
  return newMatrix;
}

void Matrix::showMatrix() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << M[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void Matrix::apply(double func(double)) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      M[i][j] = func(M[i][j]);
    }
  }
}

double Matrix::random(int min, int max) {
  return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

Matrix Matrix::fromVector(std::vector<std::vector<double>> V) {
  int new_rows = V.size();
  int new_cols = V[0].size();
  Matrix newMatrix(new_rows, new_cols);
  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < new_cols; j++) {
      newMatrix.M[i][j] = V[i][j];
    }
  }
  return newMatrix;
}

void Matrix::randomize(int rows_, int cols_) {
  rows = rows_;
  cols = cols_;
  // Initialize the matrix
  M = std::vector<std::vector<double>>(rows, std::vector<double>(cols));
  // Initialize the matrix with random numbers
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double random_number = random(-1, 1);
      // double random_number = rand() % 10 + 1;
      M[i][j] = random_number;
    }
  }
}