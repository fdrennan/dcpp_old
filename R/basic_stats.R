#' Gives the slope between two vectors
#'
#' @description
#' \code{slopeR()} Runs the same function as dcpp_slope but in the R language. 
#'
#' @param x   
#' @param y   
#'
#' @export slopeR
slopeR <-
  function(x, y) {
    
    n = length(x)
    s_x   = sum(x)
    s_y = sum(y)
    s_xx = x%*%x
    s_xy = x%*%y
    numer = n * s_xy - s_x * s_y
    denom = n * s_xx - s_x * s_x
    
    if (denom == 0) a = 2
    else a = numer / denom
    
    if (abs(a) > 1) {  
      s_yy = y%*%y
      new_denom = n * s_yy - s_y * s_y;
      a = new_denom / numer
    }
    
    a
  }

#' Gives the sum of a vector
#'
#' @description
#' \code{meanR()} Runs the same function as dcpp_sum but in the R language. 
#'
#' @param x   
#'
#' @export sumR
sumR <-
  function(x) {
    
    # Create a variable to iterate through the sum of x
    s_x = vector(mode = 'double', length = 1)
    
    # Take each x value and sum them all up
    for(i in seq_along(x)) {
      s_x = x[i] + s_x 
    }
    
    s_x
  }

#' Gives the sum of a vector
#'
#' @description
#' \code{meanR()} Runs the same function as dcpp_fibonacci but in the R language. 
#'
#' @param x   
#'
#' @export fibR
fibR <- function(x) {
  if(x <= 1) {
    return(x)
  } else {
    return(fibR(x-1) + fibR(x-2))
  }
}
