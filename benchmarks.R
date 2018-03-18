library(microbenchmark)

x = 1:100
y = 2*x - 3

microbenchmark(
  sum(x),     # base R function
  sumR(x),    # sum function written in R
  dcpp_sum(x) # sum function written in C++
)

microbenchmark(
  b$coefficients[2], # To get slope, you build a linear model in R
  slopeR(x, y),      # Getting the slope written in R
  dcpp_slope(x, y)   # Slope written in C++
)

microbenchmark(
  fibR(20),
  dcpp_fib(20),
  unit = 's'
)
