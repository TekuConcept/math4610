# Add Vector Method

**Routine Name:** add

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will add two vectors of the same size together and return the result.

**Input:** Two vectors of the same size.

**Output:** The sum of the vectors.

**Usage/Example:**

Code can be written to add the vectors:

    auto sum = math4610::add<double>(
        { 1, 2, 3, 4, 5 },
        { 0, 9, 8, 7, 6 }
    );
    VERBOSE("Sum: " << sum);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    std::vector<T>
    add(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size())
            throw std::runtime_error(
                "cannot add vectors of different sizes");
        std::vector<T> result;
        result.resize(__lhs.size());
        for (size_t i = 0; i < result.size(); i++)
            result[i] = __lhs[i] + __rhs[i];
        return result;
    }

**Last Modified:** October/2019
