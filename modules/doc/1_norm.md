# 1-Norm Method

**Routine Name:** norm

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the 1-norm of a vector of size `n`. If the vector has zero elements, then zero is returned.

**Input:** The vector to analyze and a norm index ( p = 1 ).

**Output:** The computed norm.

**Usage/Example:**

Code can be written to find the vector's norm:

    auto index = 1;
    auto norm = math4610::norm<double>(
        { 5, 4, 3, 2, 1 },
        index
    );
    VERBOSE("Norm: " << norm);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    T
    norm(
        const std::vector<T>& __v,
        size_t                __p)
    {
        if (__p == 0) return infinite_norm(__v);
        if (__v.size() == 0) return (T)0;
        T sum = 0;
        for (const auto& x : __v)
            sum += std::pow(x, __p);
        return std::pow(sum, 1 / __p);
    }

**Last Modified:** October/2019
