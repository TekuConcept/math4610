# Tasksheet 1

## Task 1:
[https://tekuconcept.github.io/](https://github.com/TekuConcept/)

## Task 2:
https://github.com/TekuConcept/math4610

## Task 3:
(Debian) Linux Mint x86_64 Terminal + Visual Studio Code

## Task 4:
https://github.com/TekuConcept/math4610/blob/master/modules/test/target_language.cpp

Can either be compiled using `cmake . && make` or by using `g++ test/target_language.cpp`

## Task 5:
https://github.com/TekuConcept/math4610/blob/master/hw_toc.md

## Task 6:

https://github.com/TekuConcept/math4610/blob/master/modules/test/central_difference.cpp

Terminal output using central difference for the equation `f(x) = 3x^3 + x^2 + 5`. The exact value was provided by the euqation `f'(x) = 9x^2 + 2x`. When `x = 8.2`, after about 40 iterations, precision starts to become a problem in the correct output value.
```
-- BEGIN --
error: 3; h = 1
error: 0.75; h = 0.5
error: 0.1875; h = 0.25
error: 0.046875; h = 0.125
error: 0.0117188; h = 0.0625
error: 0.00292969; h = 0.03125
error: 0.000732422; h = 0.015625
error: 0.000183105; h = 0.0078125
error: 4.57764e-05; h = 0.00390625
error: 1.14441e-05; h = 0.00195312
error: 2.86102e-06; h = 0.000976562
error: 7.15256e-07; h = 0.000488281
error: 1.78814e-07; h = 0.000244141
error: 4.47035e-08; h = 0.00012207
error: 1.11759e-08; h = 6.10352e-05
f'(8) = 
Approximately: 592
Exactly:       592
-- END OF LINE --
```

## Task 7:
* [absolute-error](https://github.com/TekuConcept/math4610/blob/master/modules/doc/errabs.md)
* [relative-error](https://github.com/TekuConcept/math4610/blob/master/modules/doc/errrel.md)

## Task 8:

* [absolute-error](https://github.com/TekuConcept/math4610/blob/master/modules/doc/errabs.md)
* [relative-error](https://github.com/TekuConcept/math4610/blob/master/modules/doc/errrel.md)
* [single-machine-epsilon](https://github.com/TekuConcept/math4610/blob/master/modules/doc/smaceps.md)
* [double-machine-epsilon](https://github.com/TekuConcept/math4610/blob/master/modules/doc/dmaceps.md)

## Task 9:

https://github.com/TekuConcept/math4610/blob/master/modules/test/central_difference.cpp

Terminal output using central difference for the equation `f(x) = exp(pi)`. The exact value was provided by the euqation `f'(x) = exp(pi)`. The algorithm used central difference to approximate the value. The algorithm is an optimised version of the one used in task-6 in that the iteration loop exits immediately if the next error is larger than the previous error.

```
-- BEGIN --
0: f'(x)=27.195; abs: 4.05428; rel: 0.175201; h = 1
1: f'(x)=24.117; abs: 0.97632; rel: 0.0421906; h = 0.5
2: f'(x)=23.3825; abs: 0.241803; rel: 0.0104493; h = 0.25
3: f'(x)=23.201; abs: 0.0603093; rel: 0.0026062; h = 0.125
4: f'(x)=23.1558; abs: 0.0150685; rel: 0.000651169; h = 0.0625
5: f'(x)=23.1445; abs: 0.00376657; rel: 0.000162768; h = 0.03125
6: f'(x)=23.1416; abs: 0.000941609; rel: 4.06906e-05; h = 0.015625
7: f'(x)=23.1409; abs: 0.0002354; rel: 1.01726e-05; h = 0.0078125
8: f'(x)=23.1408; abs: 5.88499e-05; rel: 2.54313e-06; h = 0.00390625
9: f'(x)=23.1407; abs: 1.47125e-05; rel: 6.35783e-07; h = 0.00195312
10: f'(x)=23.1407; abs: 3.67811e-06; rel: 1.58946e-07; h = 0.000976562
11: f'(x)=23.1407; abs: 9.19529e-07; rel: 3.97364e-08; h = 0.000488281
12: f'(x)=23.1407; abs: 2.29881e-07; rel: 9.93406e-09; h = 0.000244141
13: f'(x)=23.1407; abs: 5.74771e-08; rel: 2.48381e-09; h = 0.00012207
14: f'(x)=23.1407; abs: 1.43598e-08; rel: 6.20544e-10; h = 6.10352e-05
15: f'(x)=23.1407; abs: 3.59139e-09; rel: 1.55198e-10; h = 3.05176e-05
16: f'(x)=23.1407; abs: 7.97424e-10; rel: 3.44598e-11; h = 1.52588e-05
17: f'(x)=23.1407; abs: 9.89324e-11; rel: 4.27526e-12; h = 7.62939e-06

f'(pi) =
Approximately: 23.1407
Exactly:       23.1407
-- END OF LINE --
```

## Task 10:
[Absolute and Relative Error Calculation](https://www.thoughtco.com/absolute-and-relative-error-calculation-609602): Absolute error is the magnitude of how far off a real measurement is from an ideal measurement. As the article demonstrated, if a book were measured using a ruler in millimeters, the level of precision would be limited to `+/- 1 mm`. Relative error is a proportional value of the absolute error with respect to the known value. Absolute error can either be represented as a decimal value or a percentage.
