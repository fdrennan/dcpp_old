#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

// [[Rcpp::export]]
double dcpp_sum(const std::vector<double>& x) {
  
  const double s_x   = std::accumulate(x.begin(), x.end(), 0.0);
  
  return s_x;
}