//Fibonacci Series using Recursion
#include<stdio.h>

// [[Rcpp::export]]
int dcpp_fib(int n)
{
  if (n <= 1)
    return n;
  return dcpp_fib(n-1) + dcpp_fib(n-2);
}
