#include <vector>

class Matrix {
 public:
  Matrix(int rows, int cols);
  Matrix();
  Matrix operator+(Matrix);
  Matrix operator-(Matrix);
  Matrix operator*(Matrix);
  Matrix operator*(double);
  Matrix dot(Matrix);
  Matrix transpose();
  Matrix fromVector(std::vector<std::vector<double>> V);

  void apply(double function(double));
  double random(int min, int max);
  void showMatrix();
  void randomize(int rows_, int cols_);

  std::vector<std::vector<double>> M;

 private:
  int cols, rows;
};