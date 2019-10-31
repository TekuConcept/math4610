# Multiply Vector Method

**Routine Name:** multiply

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will multiply a vector by a matrix.

**Input:** A matrix and a vector. The vector's size must be equal to the matrix's number of columns.

**Output:** The vector result.

**Usage/Example:**

Code can be written as follows:

    std::vector<double> m_data{
        0, 1, 2,
        3, 4, 5,
        6, 7, 8
    };
    matrix<double> A(3, 3, m_data.data());
    auto b = math4610::multiply<double>(A, { 20, 15, 10 });
    VERBOSE("Ax = " << b);

**Implementation/Code:** ( [vector_ops.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/vector_ops.h) )

    template <typename T>
    std::vector<T>
    multiply(
        const matrix<T>&      __A,
        const std::vector<T>& __v)
    {
        if (__A.cols() != __v.size())
            throw std::runtime_error(
                "vector and matrix sizes do not match");
        std::vector<T> result;
        result.resize(__A.rows());
        size_t y;
        #pragma omp parallel for
        for (y = 0; y < __A.rows(); y++) {
            auto* row = __A.at(y, 0);
            result[y] = 0;
            for (size_t x = 0; x < __A.cols(); x++)
                result[y] += row[x] * __v[x];
        }
        return result;
    }

**Last Modified:** October/2019
