# Tasksheet 3

## Task 1:

* [newton-raphson](https://github.com/TekuConcept/math4610/blob/master/modules/doc/newton.md)

## Task 2:

* [secant](https://github.com/TekuConcept/math4610/blob/master/modules/doc/secant.md)

## Task 3:

Newton-Raphson:
```
0: 0.8
1: 1.19306
2: 1.1034
3: 1.09637
4: 1.09633
5: 1.09633
Root: 1.09633
```

Secant:
```
0: 0.8
1: 1
2: 1.12454
3: 1.09403
4: 1.09628
5: 1.09633
Root: 1.09633
```

The newton-raphson and secant methods applied to the function `f(x) = xcosh(x) + x^3 + pi` found the root in significantly less iterations than the bisection and fixed-point iteration methods. The newton-raphson and secant methods each took slightly different approaches to finding the root but ended up taking exactly the same number of iterations for this particular input function and returned about the same result.

* [root_finding.cpp](https://github.com/TekuConcept/math4610/blob/master/modules/test/root_finding.cpp)


## Task 4:

* [bisect-newton](https://github.com/TekuConcept/math4610/blob/master/modules/doc/bisect_newton.md)

## Task 5:

* [bisect-secant](https://github.com/TekuConcept/math4610/blob/master/modules/doc/bisect_secant.md)

## Task 6:

* [newton-raphson](https://github.com/TekuConcept/math4610/blob/master/modules/doc/newton.md)
* [secant](https://github.com/TekuConcept/math4610/blob/master/modules/doc/secant.md)
* [bisect-newton](https://github.com/TekuConcept/math4610/blob/master/modules/doc/bisect_newton.md)
* [bisect-secant](https://github.com/TekuConcept/math4610/blob/master/modules/doc/bisect_secant.md)

## Task 7:

* [multi_bisect](https://github.com/TekuConcept/math4610/blob/master/modules/doc/multi_bisect.md)
* [root_finding_2](https://github.com/TekuConcept/math4610/blob/master/modules/test/root_finding_2.cpp)

## Task 8:

* [multi_secant](https://github.com/TekuConcept/math4610/blob/master/modules/doc/multi_secant.md)
* [root_finding_2](https://github.com/TekuConcept/math4610/blob/master/modules/test/root_finding_2.cpp)

## Task 9:

* [multi_netwon](https://github.com/TekuConcept/math4610/blob/master/modules/doc/multi_newton.md)
* [root_finding_2](https://github.com/TekuConcept/math4610/blob/master/modules/test/root_finding_2.cpp)

## Task 10:

* https://www.ugrad.math.ubc.ca/coursedoc/math100/notes/approx/newton.html

Polynomials with degrees greater than or equal to three tend to have non-trivial roots associated with them. Root-finding numerical methods help to find close approximations to roots of such polynomials. In some cases when hardware does not support the division operation, iterative root-finding can be used to emulate it.
