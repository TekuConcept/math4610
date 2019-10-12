# Secant Method

**Routine Name:** secant

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the closely-approximated root of the input function, `f(x)`, using the open-loop secant method. Secant method is a modified version of the newton-raphson method, which does not require the function's derivative. The Secant formula follows `x_{i+1} = x_i + f(x_{i-1})(x_{i-1} - x_i) / [f(x_{i-1}) - f(x_i)]`.

**Input:** An initial guess, the next guess, and the function.

**Output:** The computed root value.

**Usage/Example:**

Consider the function `f(x) = 5x^3 + x^2 + 7`, code can be written to find its root:

    auto initial_guess = 1.2;
    auto next_guess = 1.5;
    auto root = math4610::secant<double>(
        initial_guess,
        next_guess,
        [](double x) -> double {
            return 5 * std::pow(x, 3) + std::pow(x, 2) + 7;
        }
    );
    VERBOSE("Root: " << root);

**Implementation/Code:** ( [secant.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/secant.h) )

    template <typename T>
    T
    secant(
        T                   __x0,
        T                   __x1,
        std::function<T(T)> __f,
        T                   __epsilon = (T)1.0E-5)
    {
        T h;
        T xi = __x0;
        T xj = __x1;
        size_t limit = 0;
        do {
            auto n1 = __f(xi);
            auto n2 = __f(xj);
            h   = (n2 * (xi - xj)) / (n1 - n2);
            xi  = xj;
            xj -= h;
            limit++;
        } while (std::abs(h) >= __epsilon && limit < 1000);
        return xj;
    }

**Last Modified:** October/2019
