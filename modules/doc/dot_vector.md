# Dot Vector Method

**Routine Name:** dot

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will dot two vectors of the same size and return the result.

**Input:** Two vectors of the same size.

**Output:** The dot product of the vectors.

**Usage/Example:**

Code can be written to find the vector's dot product:

    auto dot = math4610::dot<double>(
        { 1, 2, 3, 4, 5 },
        { 0, 9, 8, 7, 6 }
    );
    VERBOSE("Dot: " << dot);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    T
    dot(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size())
            throw std::runtime_error(
                "cannot dot vectors of different sizes");
        T result = (T)0;
        size_t size = __lhs.size();
        for (size_t i = 0; i < size; i++)
            result += __lhs[i] * __rhs[i];
        return result;
    }

**Last Modified:** October/2019
