#include "Matrix.h"

class NN {
  // Methods
 public:
  NN(int input_nodes, int hidden_nodes, int output_nodes);
  Matrix feedfoward(Matrix X);
  Matrix train(Matrix X, Matrix y);

 private:
  // Variables stay private
  int input_nodes, hidden_nodes, output_nodes;
  double learning_rate = 0.1;
  Matrix weights_ih;
  Matrix weights_ho;
  Matrix bias_ih;
  Matrix bias_ho;
};
