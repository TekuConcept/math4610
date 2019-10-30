# Tasksheet 4

## Task 1:

Open-loop root finding algorithms may sometimes diverge. The hybrid methods first uses the bisection method, which is closed-loop and converges. As such, the hybrid methods can hone in on the target, then switch to an open-loop method to expidite the search.

## Task 2:

* [1_norm](https://github.com/TekuConcept/math4610/blob/master/modules/doc/1_norm.md)
* [2_norm](https://github.com/TekuConcept/math4610/blob/master/modules/doc/2_norm.md)
* [inf_norm](https://github.com/TekuConcept/math4610/blob/master/modules/doc/inf_norm.md)

## Task 3:

* [1_norm_abserr](https://github.com/TekuConcept/math4610/blob/master/modules/doc/1_norm_abserr.md)
* [1_norm_relerr](https://github.com/TekuConcept/math4610/blob/master/modules/doc/1_norm_relerr.md)
* [2_norm_abserr](https://github.com/TekuConcept/math4610/blob/master/modules/doc/2_norm_abserr.md)
* [2_norm_relerr](https://github.com/TekuConcept/math4610/blob/master/modules/doc/2_norm_relerr.md)
* [inf_norm_abserr](https://github.com/TekuConcept/math4610/blob/master/modules/doc/inf_norm_abserr.md)
* [inf_norm_relerr](https://github.com/TekuConcept/math4610/blob/master/modules/doc/inf_norm_relerr.md)

## Task 4:

* [add](https://github.com/TekuConcept/math4610/blob/master/modules/doc/add_vector.md)
* [subtract](https://github.com/TekuConcept/math4610/blob/master/modules/doc/sub_vector.md)
* [scale](https://github.com/TekuConcept/math4610/blob/master/modules/doc/scale_vector.md)

## Task 5: TODO

Write a code that implements a "SAXPY" operation involing input of a couple of vectors and a scalar. Do an internet search to find out what a SAXPY operation is. Add the routine to your shared library and the software manual.

## Task 6: TODO

Write codes to implement (1) the dot product of two vectors and (2) the cross product of two vectors. As usual, add these to your shared library and software manual.
* [dot](https://github.com/TekuConcept/math4610/blob/master/modules/doc/dot_vector.md)

## Task 7: TODO

Create a routine that will return the output from multiplying a matrix into a vector from the left. Do this for a general rectangular matrix, A. That is, `y = Ax`

## Task 8:

    hello parallel world from thread #1
    hello parallel world from thread #0
    hello parallel world from thread #2
    hello parallel world from thread #3

( Two cores, Four hyperthreads )

## Task 9: TODO

Use OpenMP to try to speed up the matrix-vector multiplication using more than one processor.

## Task 10:

https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
By default, GCC uses optimization level 0. Every line of code translates to one or more instructions. Level 1 optimization adds speed and binary size improvements without increasing compile time. Level 2, which is usually a nominal level of optimisation for most programs, takes a little longer to compile but provides runtime benefits and reduced disk usage. Level 3, size, and fast optimization levels head in the computer science realm, that is, the developer needs to determine which they consider more important when optimizing: speed or size.
