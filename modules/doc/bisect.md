# Bisection Method

**Routine Name:** bisection

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the closely-approximated root of the input function, `f(x)` using the closed-loop bisection method. Two guesses of opposite signs surround the target root. The guesses get closer to the actual root in one-bit increments each iteration.

**Input:** The function, f(x), two guesses of opposite signs that surround the root, an optional non-zero target value for which to find the root, and an optional minimum error epsilon.

**Output:** The computed root value.

**Usage/Example:**

Consider the function `f(x) = xcosh(x) + x^3 = PI`, code can be written to find its root:

    auto upper_bound = 1.5;
    auto lower_bound = 0.5;
    auto root = math4610::bisection<double>(
        [](double x) -> double {
            return x * std::cosh(x) + std::pow(x, 3);
        },
        upper_bound,
        lower_bound,
        M_PI
    );
    VERBOSE("Root: " << root);

The output of the function in the example above is:

```
 0| xu: 1.5     xl: 0.5     xr: 1
 1| xu: 1.5     xl: 1       xr: 1.25
 2| xu: 1.25    xl: 1       xr: 1.125
 3| xu: 1.125   xl: 1       xr: 1.0625
 4| xu: 1.125   xl: 1.0625  xr: 1.09375
 5| xu: 1.125   xl: 1.09375 xr: 1.10938
 6| xu: 1.10938 xl: 1.09375 xr: 1.10156
 7| xu: 1.10156 xl: 1.09375 xr: 1.09766
 8| xu: 1.09766 xl: 1.09375 xr: 1.0957
 9| xu: 1.09766 xl: 1.0957  xr: 1.09668
10| xu: 1.09668 xl: 1.0957  xr: 1.09619
11| xu: 1.09668 xl: 1.09619 xr: 1.09644
12| xu: 1.09644 xl: 1.09619 xr: 1.09631
13| xu: 1.09644 xl: 1.09631 xr: 1.09637
14| xu: 1.09637 xl: 1.09631 xr: 1.09634
15| xu: 1.09634 xl: 1.09631 xr: 1.09633
Root: 1.09633
```

**Implementation/Code:** ( [bisect.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/bisect.h) )

    template <typename T>
    T
    bisection(
        std::function<T(T)> __f,
        T                   __upper_bound,
        T                   __lower_bound,
        T                   __target = (T)0,
        T                   __epsilon = (T)1.0E-5)
    {
        auto g        = [&](T x) -> T { return __f(x) - __target; };
        T upper_bound = __upper_bound;
        T lower_bound = __lower_bound;
        T root, error = (T)0.0;
        do {
            root        = (lower_bound + upper_bound) / 2;
            auto g_root = g(root);
            error       = std::abs(g_root);
            auto check  = g(lower_bound) * g_root;
            if (check < 0)      upper_bound = root;
            else if (check > 0) lower_bound = root;
            else break;
        } while (error >= __epsilon);
        return root;
    }

**Last Modified:** September/2019
