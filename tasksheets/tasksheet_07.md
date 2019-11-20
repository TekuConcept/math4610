# Tasksheet 7

## Task 1:
* [steepest-descent](https://github.com/TekuConcept/math4610/blob/master/modules/doc/steepest_descent_matrix.md)

## Task 2:
* [steepest-descent-test](https://github.com/TekuConcept/math4610/blob/master/modules/test/matrix_test.cpp) (`n = 500` clocked at about two seconds to complete)

## Task 3:
* [conjugate-gradient](https://github.com/TekuConcept/math4610/blob/master/modules/doc/conjugate_gradient_matrix.md)

## Task 4:
* [steepest-descent vs conjugate-gradient](https://github.com/TekuConcept/math4610/blob/master/modules/test/matrix_test.cpp)
- steepest descent:   227
- conjugate gradient: 999

## Task 5:
* [steepest-descent vs conjugate-gradient vs guassian-elimination](https://github.com/TekuConcept/math4610/blob/master/modules/test/matrix_test.cpp)
- steepest descent:     0.3032 ms
- conjugate gradient:   4.4210 ms
- gaussian elimination: 0.0155 ms

## Task 6:
* [steepest-descent vs conjugate-gradient vs jacobi](https://github.com/TekuConcept/math4610/blob/master/modules/test/matrix_test.cpp)
- steepest descent:     1.4440 ms
- conjugate gradient:   3.6270 ms
- jacobi:               0.3691 ms

## Task 7:
* [steepest-descent vs conjugate-gradient vs gauss-seidel](https://github.com/TekuConcept/math4610/blob/master/modules/test/matrix_test.cpp)
- steepest descent:     1.44400 ms
- conjugate gradient:   3.62700 ms
- gauss-seidel:         0.08211 ms

## Task 8: TODO
Implement a matrix multiplication routine for a tridiagonal matrix that avoids as many computations with zeros as possible. Use the vector form of matrix storage to store the three nonzero diagonals. Create a software manual page for the method.

## Task 9: TODO
Create an analogous routine where the matrix is penta-diagonal with two diagonals above and below the main diagonal of the matrix. Use 5 vectors to store the matrix. As always, document the method in your software manual.

## Task 10:
https://en.wikipedia.org/wiki/Conjugate_gradient_method The conjugate gradient method is similar to steepest descent but is used for symmetric, positive definite matrices. The conjugate gradient method can converge in a number of iterations less than or equal to the size of the matrix when there is no round-off error. The method can be used for unconstrained optimization problems such as energy minimization.
