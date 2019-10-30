# Infinite-Norm Method

**Routine Name:** infinite_norm

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the infinite-norm of a vector of size `n`. If the vector has zero elements, then zero is returned.

**Input:** The vector to analyze.

**Output:** The computed norm.

**Usage/Example:**

Code can be written to find the vector's norm:

    auto norm = math4610::infinite_norm<double>({ 5, 4, 3, 2, 1 });
    VERBOSE("Norm: " << norm);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    T
    infinite_norm(const std::vector<T>& __v)
    {
        if (__v.size() == 0) return (T)0;
        auto result = __v.front();
        for (size_t i = 0; i < __v.size(); i++)
            result = std::max(result, __v[i]);
        return result;
    }

**Last Modified:** October/2019
