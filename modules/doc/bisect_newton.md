# Bisect-Newton Hybrid

**Routine Name:** bisect_newton

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the closely-approximated root of the input function, `f(x)`, first using the closed-loop bisection method and then the open-loop newton-raphson method. When the bisection method has drawn close enough to the root, the algorithm will transition to the faster newton-raphson method.

**Input:** An upper bound and lower bound that enclose the root, and the function and its derivative.

**Output:** The computed root value.

**Usage/Example:**

Consider the function `f(x) = 5x^3 + x^2 + 7`, code can be written to find its root:

    auto upper_bound = -1.0;
    auto lower_bound = -2.0;
    auto root = math4610::bisect_newton<double>(
        [](double x) -> double { // function
            return 5 * std::pow(x, 3) + std::pow(x, 2) + 7;
        },
        [](double x) -> double { // and its derivative
            return 15 * std::pow(x, 2) + 2 * x;
        },
        upper_bound,
        lower_bound
    );
    VERBOSE("Root: " << root);

**Implementation/Code:** ( [bisect_newton.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/bisect_newton.h) )

    template <typename T>
    T
    bisect_newton(
        std::function<T(T)> __f,
        std::function<T(T)> __df,
        T                   __upper_bound,
        T                   __lower_bound,
        T                   __epsilon = (T)1.0E-5,
        T                   __epsilon_scalar = (T)1.0E3)
    {
        auto x0 = bisection<T>(
            __f,
            __upper_bound,
            __lower_bound,
            /*target=*/0,
            __epsilon * __epsilon_scalar);
        return newton_raphson<T>(
            x0,
            __f,
            __df,
            __epsilon);
    }

**Last Modified:** October/2019
