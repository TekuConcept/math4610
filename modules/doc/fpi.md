# Fixed Point Iteration

**Routine Name:** fixed_point_iteration

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the closely-approximated root of the fixed-point input function, `g(x)`. It uses the initial condition as a starting point. The next value, `x_{i+1}`, comes from the computation `g(x_i)`. The iterative process may converge or diverge depending on the given function.

Use the fixed-point therom to determine if the function, `g(x)`, will converge or diverge. The therom states that for a function, `g(x)`, we find the derivative, `g'(x)`. If `|g'(x)| <= k; 0 < k < 1`, the function will converge.

**Input:** The function, g(x), the initial non-zero starting value, and an optional minimum error epsilon.

**Output:** The computed root value on success or a flag suggesting a computation error.

**Usage/Example:**

Consider the function `f(x) = exp(-x) - x`, code can be written to find its root:

    auto success = true;
    auto root    = 0.0;
    auto INITIAL = 1.0;
    success = math4610::fixed_point_iteration<double>(
        [](double x) -> double { return std::exp(-x); },
        &root, INITIAL
    );
    if (success) VERBOSE("Root: " << root);
    else VERBOSE("Attemp failed");

The output of the function in the example above is:

```
 0| x: 1        c: 0.367879 e: 1.71828
 1| x: 0.367879 c: 0.692201 e: 0.468536
 2| x: 0.692201 c: 0.500474 e: 0.383091
 3| x: 0.500474 c: 0.606244 e: 0.174468
 4| x: 0.606244 c: 0.545396 e: 0.111566
 5| x: 0.545396 c: 0.579612 e: 0.0590335
 6| x: 0.579612 c: 0.560115 e: 0.0348087
 7| x: 0.560115 c: 0.571143 e: 0.019308
 8| x: 0.571143 c: 0.564879 e: 0.0110887
 9| x: 0.564879 c: 0.568429 e: 0.00624419
10| x: 0.568429 c: 0.566415 e: 0.00355568
11| x: 0.566415 c: 0.567557 e: 0.00201197
12| x: 0.567557 c: 0.566909 e: 0.00114256
13| x: 0.566909 c: 0.567276 e: 0.000647516
14| x: 0.567276 c: 0.567068 e: 0.000367388
15| x: 0.567068 c: 0.567186 e: 0.000208312
16| x: 0.567186 c: 0.567119 e: 0.000118159
17| x: 0.567119 c: 0.567157 e: 6.70078e-05
18| x: 0.567157 c: 0.567135 e: 3.80047e-05
19| x: 0.567135 c: 0.567148 e: 2.15536e-05
20| x: 0.567148 c: 0.567141 e: 1.22241e-05
Root: 0.567148
```

**Implementation/Code:** ( [fpi.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/fpi.h) )

    template <typename T>
    bool
    fixed_point_iteration(
        std::function<T(T)> __g,
        T*                  __root,
        T                   __initial,
        T                   __epsilon = (T)1.0E-5)
    {
        T x = __initial;
        for (int i = 0; i < 1000; i++) {
            auto c     = __g(x);
            auto error = approximate_error(c, x);
            x = c;
            if (std::isinf(c) || std::isnan(c)) return false;
            if ((error == (T)0) || (error < __epsilon)) break;
            if (i == (1000 - 1)) return false;
        }
        if (__root) *__root = x;
        return true;
    }

**Last Modified:** September/2019