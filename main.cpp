#include <math.h>
#include <fstream>
#include <iostream>
// #include "Matrix.h"
#include <vector>
#include "NN.h"

std::ifstream fin("input.txt");

double twotimes(double n) { return 2 * n; }

int main() {
  srand(time(0));

  int rows, cols;
  fin >> rows >> cols;
  std::vector<std::vector<double>> XV(rows, std::vector<double>(cols));
  std::vector<std::vector<double>> yV(rows, std::vector<double>(1));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      fin >> XV[i][j];
    }
  }
  for (int i = 0; i < rows; i++) {
    fin >> yV[i][0];
  }
  Matrix X(rows, cols);
  Matrix y(rows, 1);
  X = X.fromVector(XV);
  y = y.fromVector(yV);

  NN NeuronalNetwork(cols, rows, 1);
  std::cout << "My predictions:    \n";
  NeuronalNetwork.train(X, y).showMatrix();
  std::cout << "\n Actual predictions: \n";
  y.showMatrix();
  return 0;
}