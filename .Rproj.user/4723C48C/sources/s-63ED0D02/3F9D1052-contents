#' Gives the slope between two vectors
#'
#' @description
#' \code{slopeR()} Runs the same function as slope but in the R language. 
#'
#' @param x   
#' @param y   
#'
#' @export MagellanSOC
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