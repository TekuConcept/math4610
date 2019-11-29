# Tasksheet 8

## Task 1:
* [power-method](https://github.com/TekuConcept/math4610/blob/master/modules/doc/power_matrix.md)

## Task 2:
* [hilbert-power-method](https://github.com/TekuConcept/math4610/blob/master/modules/test/matrix_test.cpp)

Example output:

    1      0.5     0.3333  0.25    0.2     0.1667  0.1429  0.125   0.1111  0.1 
    0.5    0.3333  0.25    0.2     0.1667  0.1429  0.125   0.1111  0.1     0.09091 
    0.3333 0.25    0.2     0.1667  0.1429  0.125   0.1111  0.1     0.09091 0.08333 
    0.25   0.2     0.1667  0.1429  0.125   0.1111  0.1     0.09091 0.08333 0.07692 
    0.2    0.1667  0.1429  0.125   0.1111  0.1     0.09091 0.08333 0.07692 0.07143 
    0.1667 0.1429  0.125   0.1111  0.1     0.09091 0.08333 0.07692 0.07143 0.06667 
    0.1429 0.125   0.1111  0.1     0.09091 0.08333 0.07692 0.07143 0.06667 0.0625 
    0.125  0.1111  0.1     0.09091 0.08333 0.07692 0.07143 0.06667 0.0625  0.05882 
    0.1111 0.1     0.09091 0.08333 0.07692 0.07143 0.06667 0.0625  0.05882 0.05556 
    0.1    0.09091 0.08333 0.07692 0.07143 0.06667 0.0625  0.05882 0.05556 0.05263 

    [-0.6995 -0.426 -0.317 -0.2555 -0.2153 -0.1866 -0.1649 -0.148 -0.1343 -0.123]

## Task 3:
* [inverse-power-method](https://github.com/TekuConcept/math4610/blob/master/modules/doc/inverse_power_matrix.md)

## Task 4:
* [hilbert-inverse-power-method](https://github.com/TekuConcept/math4610/blob/master/modules/test/matrix_test.cpp)
    
Example output:

    1      0.5     0.3333  0.25    0.2     0.1667  0.1429  0.125   0.1111  0.1 
    0.5    0.3333  0.25    0.2     0.1667  0.1429  0.125   0.1111  0.1     0.09091 
    0.3333 0.25    0.2     0.1667  0.1429  0.125   0.1111  0.1     0.09091 0.08333 
    0.25   0.2     0.1667  0.1429  0.125   0.1111  0.1     0.09091 0.08333 0.07692 
    0.2    0.1667  0.1429  0.125   0.1111  0.1     0.09091 0.08333 0.07692 0.07143 
    0.1667 0.1429  0.125   0.1111  0.1     0.09091 0.08333 0.07692 0.07143 0.06667 
    0.1429 0.125   0.1111  0.1     0.09091 0.08333 0.07692 0.07143 0.06667 0.0625 
    0.125  0.1111  0.1     0.09091 0.08333 0.07692 0.07143 0.06667 0.0625  0.05882 
    0.1111 0.1     0.09091 0.08333 0.07692 0.07143 0.06667 0.0625  0.05882 0.05556 
    0.1    0.09091 0.08333 0.07692 0.07143 0.06667 0.0625  0.05882 0.05556 0.05263 

    [-1.531e+07 1.331e+09 -2.85e+10 2.601e+11 -1.245e+12 3.43e+12 -5.64e+12 5.461e+12 -2.871e+12 6.323e+11]

## Task 5: TODO
Implement the power method with shifting to try to estimate eignevalues of a matrix. Include a page in your software manual. Try to find as eigenvalues not equal to the largest or smallest. Use a symmetric diagonally dominant matrix to test the code.

## Task 6: TODO
Try out your shifted power method on the Hilbert matrix of order n = 10.

## Task 7: TODO
Knowing that the condition number of a matrix in the 2-norm is related to the largest and smallest eigenvalues, write a routine that will compute an estimate of the 2-condition number using the power method and inverse power method.

## Task 8: TODO
Try out the condition number code on the Hilber matrix for n = 10. Does this work?

## Task 9: TODO
Combine the tridiagonal matrix multiplication routine to compute the 2-condition number of a tridiagonal matrix. Use a symmetric diagonally dominant tridiagonal matrix to test the code. Use a tridiagonal matrix with 
n = 10, 100, 1000, 10000. Report the results including execution time.

## Task 10: TODO
Search the internet for sites that document the use of Power iteration and/or Inverse Power Iteration. Write a brief paragraph (3 or 4 sentences) that describe your findings. Include links to the sites you cite.
