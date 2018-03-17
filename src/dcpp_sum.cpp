#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

// [[Rcpp::export]]
double dcpp_sum(const std::vector<double>& r_vector) {
  
  int summation_vector = 0;
  
  for(int i = 0; i < r_vector.size(); i = i + 1 ) {
    
    summation_vector = summation_vector + r_vector[i];
    
  }
  
  return summation_vector;
}