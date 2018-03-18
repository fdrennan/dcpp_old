// Implements linear regression using gradient descent. 

#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <cmath>
#include <limits>

using namespace std;

class LinearRegression {
public:
  
  LinearRegression() {};
  ~LinearRegression() {};
  
  
  LinearRegression(vector<double>& m_x_vals_, vector<double> m_y_vals_) : m_x_vals(m_x_vals_),
  m_y_vals(m_y_vals_),m_num_elems(m_y_vals_.size()) {}
  
  void trainAlgorithm(int num_iters_, double a_init_, double b_init_) {
    
    int iter = 0;
    m_a = a_init_;
    m_b = b_init_;
    
    while(iter < num_iters_) {
      //update the gradient 
      double step = 0.02;
      double a_grad = 0;
      double b_grad = 0;
      
      // compute the gradient 
      for (int i = 0; i < m_num_elems; i++) {
        a_grad += m_x_vals[i] * ((m_a * m_x_vals[i] + m_b) - m_y_vals[i]);
      }
      
      a_grad = (2 * a_grad) / m_num_elems;
      
      // compute the gradient of the error wrt to b
      for (int i = 0; i < m_num_elems; i++) {
        b_grad += ((m_a * m_x_vals[i] + m_b) - m_y_vals[i]);
      }
      
      a_grad = (2 * b_grad) / m_num_elems;
      
      // take a step
      m_a = m_a - (step * a_grad);
      m_b = m_b - (step * b_grad);
      cout << "a:\t" << m_a << ",b:\t" << m_b << "\r\n";
      cout << "a_grad:\t" << a_grad << "b_grad:\t" << b_grad << "\t\r\n";
      iter ++;
      
    }
    
  }
  
  double regress(double x) {
    double res = m_a * x + m_b;
    return res;
  }
private:
  
  vector<double> m_x_vals;
  vector<double> m_y_vals;
  double m_num_elems;
  double m_a;
  double m_b;
  
  
};