# Newton-Raphson Method

**Routine Name:** newton_raphson

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the closely-approximated root of the input function, `f(x)`, using the open-loop newton-raphson method. The Newton-Raphson formula follows `x_{i+1} = x_i - f(x_i) / f'(x_i)`. If `(|f(x) * f"(x)| / |(f'(x))^2|) < 1`, the newton-raphson method will converge.

**Input:** An initial guess, and the function and its derivative.

**Output:** The computed root value.

**Usage/Example:**

Consider the function `f(x) = 5x^3 + x^2 + 7`, code can be written to find its root:

    auto initial_guess = 1.5;
    auto root = math4610::newton_raphson<double>(
        initial_guess,
        [](double x) -> double { // function
            return 5 * std::pow(x, 3) + std::pow(x, 2) + 7;
        },
        [](double x) -> double { // and its derivative
            return 15 * std::pow(x, 2) + 2 * x;
        }
    );
    VERBOSE("Root: " << root);

**Implementation/Code:** ( [newton.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/newton.h) )

    template <typename T>
    T
    newton_raphson(
        T                   __x0,
        std::function<T(T)> __f,
        std::function<T(T)> __df,
        T                   __epsilon = (T)1.0E-5)
    {
        T h, x = __x0;
        size_t limit = 0;
        do {
            h = __f(x) / __df(x);
            x -= h;
            limit++;
        } while (std::abs(h) >= __epsilon && limit < 1000);
        return x;
    }

**Last Modified:** October/2019
