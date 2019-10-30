# 2-Norm Absolute Error

**Routine Name:** absolute_error

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will measure the absolute error using 2-norm.

**Input:** The approximate and exact vectors and the norm index ( p = 2 ).

**Output:** The absolute error.

**Usage/Example:**

Code can be written to find the error:

    auto index = 2;
    auto error = math4610::absolute_error<double>(
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 0 },
        index
    );
    VERBOSE("Absolute Error: " << error);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    inline T
    absolute_error(
        std::vector<T> __approximate_vector,
        std::vector<T> __exact_vector,
        size_t         __p = 0)
    {
        auto difference = subtract<T>(
            __approximate_vector,
            __exact_vector);
        return norm<T>(difference, __p);
    }

**Last Modified:** October/2019
