# Cross Vector Method

**Routine Name:** cross

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will cross two vectors in R3 space.

**Input:** Two vectors in R3 space.

**Output:** The cross product of the vectors in R3 space.

**Usage/Example:**

Code can be written to find the vector's cross product:

    auto cross = math4610::cross<double>(
        { 1, 2, 3 },
        { 0, 9, 8 }
    );
    VERBOSE("Cross: " << cross);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    std::vector<T>
    cross(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size() && __lhs.size() != 3)
            throw std::runtime_error("cannot cross vectors");
        return {
            __lhs[1] * __rhs[2] - __lhs[2] * __rhs[1],
            __lhs[2] * __rhs[0] - __lhs[0] * __rhs[2],
            __lhs[0] * __rhs[1] - __lhs[1] * __rhs[0]
        };
    }

**Last Modified:** October/2019
