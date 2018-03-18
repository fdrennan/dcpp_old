#include "LinearRegression.h"

int main (int argc, char ** argv) {
  
  vector<double> y({2.8, 2.9, 7.6, 9, 8.6});
  vector<double> x({1, 2, 3, 4, 5});
  LinearRegression lr(x, y);
  lr.trainAlgorithm(1000, 3, -10);
  
  cout << "\n Predicted Value " << lr.regress(3) << endl;
  return 1;
}