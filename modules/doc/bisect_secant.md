# Bisect-Secant Hybrid

**Routine Name:** bisect_secant

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the closely-approximated root of the input function, `f(x)`, first using the closed-loop bisection method and then the open-loop secant method. When the bisection method has drawn close enough to the root, the algorithm will transition to the faster secant method. Unlike the bisect_newton hybrid, this hybrid does not require a derivative of the input function.

**Input:** An upper bound and lower bound that enclose the root, and the function.

**Output:** The computed root value.

**Usage/Example:**

Consider the function `f(x) = 5x^3 + x^2 + 7`, code can be written to find its root:

    auto upper_bound = -1.0;
    auto lower_bound = -2.0;
    auto root = math4610::bisect_secant<double>(
        [](double x) -> double {
            return 5 * std::pow(x, 3) + std::pow(x, 2) + 7;
        },
        upper_bound,
        lower_bound
    );
    VERBOSE("Root: " << root);

**Implementation/Code:** ( [bisect_secant.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/bisect_secant.h) )

    template <typename T>
    T
    bisect_secant(
        std::function<T(T)> __f,
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
        return secant<T>(
            __lower_bound,
            x0,
            __f,
            __epsilon);
    }

**Last Modified:** October/2019
