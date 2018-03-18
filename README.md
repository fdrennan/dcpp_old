dcpp
================

-   [Introduction](#introduction)
-   [Overviews](#Overviews)
    -   [C++ Code](#C++ Code)
    -   [R Code](#R Code)
    -   [Benchmarks](#Benchmarks)

Introduction
------------

`dcpp` is an R package that I've created to help me learn cpp. `dcpp` stands for Dren C++.

Overview
----------------------------

I am learning C++ and have found the motivation to do so through using R. R has built in capabilities to call C++ code from R. In order to grow as a programmer and data scientist, I believe it is important to learn a *real* programming language. I love R and want to be an even more powerful user. 

### C++ Code

You will find C++ code in `src` as wellas `inst`. Code in `inst` can be run by finding a given folder and running `a.out`. Code in `src` will show up when building the R package. 

### R Code

Similar R code is located in the R folder. Each R function correlates with a given C++ function. When the package is loaded, `fibR` associates with `dcpp_fib`. `sumR` is associated with `dcpp_sum`, etc. 

### Benchmarks 
A folder called `benchmarks.R` is in the home directory and it has the different functions set up for speed tests. You can compare the performance of the functions there. 