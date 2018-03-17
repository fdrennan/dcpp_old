#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

// [[Rcpp::export]]
double slope(const std::vector<double>& x, const std::vector<double>& y) {
  
  const double n     = x.size();
  const double s_x   = std::accumulate(x.begin(), x.end(), 0.0);
  const double s_y   = std::accumulate(y.begin(), y.end(), 0.0);
  const double s_xx  = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
  const double s_xy  = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
  const double numer = n * s_xy - s_x * s_y;  // The same regardless of inversion (both terms here are commutative)
  const double denom = n * s_xx - s_x * s_x;  // Will change if inverted; use this for now
  double       a;
  
  if (denom == 0) a = 2;  // If slope is vertical, force variable inversion calculation
  else a = numer / denom;
  
  if (std::abs(a) > 1) {  // Redo with variable inversion if slope is steeper than 1
    const double s_yy = std::inner_product(y.begin(), y.end(), y.begin(), 0.0);
    const double new_denom = n * s_yy - s_y * s_y;
    a = new_denom / numer;  // Invert the fraction because we've mirrored it around x=y
  }
  
  return a;
}