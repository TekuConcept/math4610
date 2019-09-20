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

Therom: g'(a,b), 0 < k < 1; |g'(x)| <= k; g(x) will converge

## Task 3:

* [fixed-point-iteration](https://github.com/TekuConcept/math4610/blob/master/modules/doc/fpi.md)
* [root-finding](https://github.com/TekuConcept/math4610/blob/master/modules/test/root_finding.cpp)

## Task 4:

* [bisection](https://github.com/TekuConcept/math4610/blob/master/modules/doc/bisect.md)
* [root-finding](https://github.com/TekuConcept/math4610/blob/master/modules/test/root_finding.cpp)

## Task 5:

Note: this is a repeat of Tasksheet 1 : Task 8.

* [single-machine-epsilon](https://github.com/TekuConcept/math4610/blob/master/modules/doc/smaceps.md)
* [double-machine-epsilon](https://github.com/TekuConcept/math4610/blob/master/modules/doc/dmaceps.md)

## Task 6:

Note: this is a repeat of Tasksheet 1 : Task 8

* [absolute-error](https://github.com/TekuConcept/math4610/blob/master/modules/doc/errabs.md)
* [relative-error](https://github.com/TekuConcept/math4610/blob/master/modules/doc/errrel.md)

## Task 7:

* [fixed-point-iteration](https://github.com/TekuConcept/math4610/blob/master/modules/doc/fpi.md)

## Task 8:

* [bisection](https://github.com/TekuConcept/math4610/blob/master/modules/doc/bisect.md)

## Task 9:

Fixed point iteration failed to produce a root result for the equation. Eight different equation arrangements for `g(x)` were tried, but the outcome was either cyclic, divergant, or unresolvable. Bisection, on the other hand, produced a root for the same equation on the first try.

Fixed point requires only a single value, while bisection requires two values. If the function, `g(x)`, is convergent, fixed point will usually converge to the root more quickly than bisection. Bisection, however, will always converge so long as the upper and lower bound guesses surround the root.

Note: the algorithm implementation for fixed point iteration was tested on a different equation, `f(x) = exp(-1) - x`, to confirm the code was working as designed. The algorithm did produce a root for the function `f(x)`.

## Task 10:

https://mat.iitm.ac.in/home/sryedida/public_html/caimna/transcendental/iteration%20methods/fixed-point/iteration.html

With respect to fixed point iteration: Some functions will not converge for any initial approximation. Some functions will converge very quickly (faster than the bisection method). Some functions will converge very slowly (potentially slower than the bisection method). A developer can optimize their program for speed by analyzing which methods converge more quickly and opting for the faster of the two.
