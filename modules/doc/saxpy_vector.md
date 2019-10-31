# SAXPY Vector Method

**Routine Name:** saxpy

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will scale the x vector and add the y vector.

**Input:** Two vectors of the same size and a scalar.

**Output:** The saxpy result.

**Usage/Example:**

Code can be written to compute the saxpy:

    auto scalar = 2.5;
    auto saxpy = math4610::saxpy<double>(
        scalar,
        { 1, 2, 3, 4, 5 },
        { 0, 9, 8, 7, 6 }
    );
    VERBOSE("SAXPY: " << saxpy);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    std::vector<T>
    saxpy(
        T                    __a,
        const std::vector<T> __x,
        const std::vector<T> __y)
    {
        if (__x.size() != __y.size())
            throw std::runtime_error(
                "cannot run against vectors of different sizes");
        std::vector<T> result;
        result.resize(__x.size());
        for (size_t i = 0; i < result.size(); i++)
            result[i] = __a * __x[i] + __y[i];
        return result;
    }

**Last Modified:** October/2019
