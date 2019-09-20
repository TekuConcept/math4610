# Tasksheet 2

## Task 1:

Consider the nonlinear equation `xcosh(x) + x^3 = pi`. Set up a root finding problem for this equation. This task does not require any code.

Let `f(x) = xcosh(x) + x^3`. `pi` is located between `f(0.5)` and `f(1.5)`.

- Using the bisection method, `c = (a + b) / 2`, to zero in on the answer. Use either (`f(a)` and `f(c)`) or (`f(c)` and `f(b)`), which have opposite signs, for the next iteration. `if [sign(f(c)) = sign(f(a))] then a = c else b = c`
- Using the false position method, `c = b - f(b)(b - a)/(f(b) - f(a))`, to zero in on the answer. Use either (`f(a)` and `f(c)`) or (`f(c)` and `f(b)`), which have opposite signs, for the next iteration. Continue until `f(c) = 0` or `f(c) < epsilon`.

## Task 2:

Consider the nonlinear equation `xcosh(x) + x^3 = pi`. Set up at least two associated fixed point iterations for this equation. You do not need to write code for this problem.

Let `f(x) = xcosh(x) + x^3` and `g(x) = x - f(x)`, `x_0 = initial value`.

- Iteration 1: `x_{i+1} = (pi/x_{i}^2 - cosh(x_{i}) / x_{i})`
- Iteration 2: `x_{i+1} = (pi - x_{i}^3) / cosh(x_{i})`

## Task 3: TODO

Write code that implements fixed point iteration for the equation defined in the previous two tasks. Try out the method on the fixed point iteration equations in Task 1 and Task 2. Make sure that the code you write is in the form of a method or subroutine that can be added to your shared library. You should also write a main program to test the code.

## Task 4: TODO

Write a code that computes the roots of a function of one variable using the Bisection method. The algorithm should be written into a subroutine or method that can be called from a main program. Include the routine in the shared library that you are creating for the course.

## Task 5:

Note: this is a repeat of Tasksheet 1 : Task 8.

* [single-machine-epsilon](https://github.com/TekuConcept/math4610/blob/master/modules/doc/smaceps.md)
* [double-machine-epsilon](https://github.com/TekuConcept/math4610/blob/master/modules/doc/dmaceps.md)

## Task 6:

Note: this is a repeat of Tasksheet 1 : Task 8

* [absolute-error](https://github.com/TekuConcept/math4610/blob/master/modules/doc/errabs.md)
* [relative-error](https://github.com/TekuConcept/math4610/blob/master/modules/doc/errrel.md)

## Task 7: TODO

Complete pages in your software manual that document the code written for functional iteration for finding the roots of a function of a single real variable. Use the results in Task 3 as examples for the software page.

## Task 8: TODO

Repeat Task 7 for the Bisection method.

## Task 9: TODO

Compare the results from functional iteration and Bisection on the problems in Tasksheet 2, Task 1 and Task2. Which provides a better approximation and on the efficiency of the methods.

## Task 10: TODO

Search the internet for sites that discuss functional iteration for root finding. Try to find sites that show the effective use of this method in real problems. Write a brief paragraph (3 or 4 sentences) that describe your findings. Include links to the sites you cite.
