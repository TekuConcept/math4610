# Absolute Error

**Routine Name:** absolute_error

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the absolute error between the exact value and the approximated value. The formula is of the form `|x - x*|`, where `x` is the approximate value and `x*` is the exact value.

**Input:** The exact value and the approximate value.

**Output:** The absolute error of the approximate value with respect to the exact value.

**Usage/Example:**

    auto exact_value = 100.0;
    auto approximate_value = 98.0;
    auto error = math4610::absolute_error(
        approximate_value,
        exact_value);

**Implementation/Code:** ( [errabs.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/errabs.h) )

    template <typename T>
    inline double absolute_error(
        T __approximate_value,
        T __exact_value)
    { return std::abs(__approximate_value - __exact_value); }

**Last Modified:** September/2019