# Infinite-Norm Relative Error

**Routine Name:** relative_error

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will measure the relative error using infinite-norm.

**Input:** The approximate and exact vectors and optionally the norm index ( p = 0 ).

**Output:** The relative error.

**Usage/Example:**

Code can be written to find the error:

    auto error = math4610::relative_error<double>(
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 0 },
    );
    VERBOSE("Relative Error: " << error);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    inline T
    relative_error(
        std::vector<T> __approximate_vector,
        std::vector<T> __exact_vector,
        size_t         __p = 0)
    {
        auto difference = subtract<T>(
            __approximate_vector,
            __exact_vector);
        return norm<T>(difference, __p) / norm<T>(__exact_value);
    }

**Last Modified:** October/2019
