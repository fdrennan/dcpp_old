#include "LinearRegression.h"

// [[Rcpp::export]]
double dcpp_LinearRegression (const std::vector<double>& x, 
                              const std::vector<double>& y) {
  
  LinearRegression lr(x, y);
  lr.trainAlgorithm(1000, 4, 0);

  cout << lr.regress(3) << endl;
  
  return lr.regress(3);
}