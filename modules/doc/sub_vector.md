# Subtract Vector Method

**Routine Name:** subtract

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will subtract the second vector from the first and return the result.

**Input:** Two vectors of the same size.

**Output:** The difference of the vectors.

**Usage/Example:**

Code can be written to find the vector's norm:

    auto difference = math4610::subtract<double>(
        { 1, 2, 3, 4, 5 },
        { 0, 9, 8, 7, 6 }
    );
    VERBOSE("Difference: " << difference);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    std::vector<T>
    subtract(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size())
            throw std::runtime_error(
                "cannot subtract vectors of different sizes");
        size_t size = __lhs.size();
        std::vector<T> result;
        result.resize(size);
        for (size_t i = 0; i < size; i++)
            result[i] = __lhs[i] - __rhs[i];
        return result;
    }

**Last Modified:** October/2019
