# Scale Vector Method

**Routine Name:** scale

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will scale a vector by a fixed amount.

**Input:** A vector and a scalar.

**Output:** The scaled vector.

**Usage/Example:**

Code can be written to find the vector's norm:

    auto scale = 2.0;
    auto vector = math4610::subtract<double>(
        { 1, 2, 3, 4, 5 },
        scale
    );
    VERBOSE("Scaled Vector: " << vector);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    std::vector<T>
    scale(
        const std::vector<T>& __v,
        T                     __s)
    {
        size_t size = __v.size();
        std::vector<T> result;
        result.resize(size);
        for (size_t i = 0; i < size; i++)
            result[i] = __s * __v[i];
        return result;
    }

**Last Modified:** October/2019
