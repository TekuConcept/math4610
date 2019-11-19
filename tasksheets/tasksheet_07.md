# Tasksheet 7

## Task 1:
* [steepest-descent](https://github.com/TekuConcept/math4610/blob/master/modules/doc/steepest_descent_matrix.md)

## Task 2: TODO
Tryout your steepest descent method on a sequence of matrices based on the Hilbert matrix. Start with `n = 4` and see how far you can go increasing `n`.

## Task 3:
* [conjugate-gradient](https://github.com/TekuConcept/math4610/blob/master/modules/doc/conjugate_gradient_matrix.md)

## Task 4: TODO
As a test of the steepest descent method versus the conjugate gradient method, write code to do the following. First, generate a square symmetric diagonally dominant matrix - you have already created such a method. Then report the number of iterations required to produce a solution to the linear system. Generate the right hand side of the system of equations using `b = Av` where all the entries of `v` are 1.

## Task 5: TODO
Compare your results in Task 4 to the use of Gaussian Elimination with backsubstitution. Report the amount of time it takes to compute the solution of the linear system for steepest descent, the conjugate gradient method, and Gaussian elimination.

## Task 6: TODO
Repeat the work in Task 5 but use Jacobi iteration instead of Gaussian elimination. Again, which runs faster.

## Task 7: TODO
Repeat Task 6 using Gauss-Seidel instead of Jacobi Iteration.

## Task 8: TODO
Implement a matrix multiplication routine for a tridiagonal matrix that avoids as many computations with zeros as possible. Use the vector form of matrix storage to store the three nonzero diagonals. Create a software manual page for the method.

## Task 9: TODO
Create an analogous routine where the matrix is penta-diagonal with two diagonals above and below the main diagonal of the matrix. Use 5 vectors to store the matrix. As always, document the method in your software manual.

## Task 10: TODO
Search the internet for sites that document the use of conjugate gradient methods. Write a brief paragraph (3 or 4 sentences) that describe your findings. Include links to the sites you cite.
https://ocw.mit.edu/courses/mathematics/18-409-topics-in-theoretical-computer-science-an-algorithmists-toolkit-fall-2009/lecture-notes/MIT18_409F09_scribe21.pdf In some special cases, steepest descent will converge in one iteration. Depending on the gradient direction, convergance can be faster or slower if at all.