library(microbenchmark)

x = 1:100
y = 2*x - 3

microbenchmark(
  sum(x),
  sumR(x),
  dcpp_sum(x)
)
