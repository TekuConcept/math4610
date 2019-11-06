# Upper Triangular Matrix

**Routine Name:** decompose

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will decompose a matrix into its upper and lower matrix components.

**Input:** The matrix to decompose.

**Output:** The upper triangular matrix.

**Usage/Example:**

Code can be written as follows:

    math4610::matrix<double> mat(
        4, 4,
        {
            1, 2, 3, 4,
            5, 1, 7, 8,
            9, 0, 1, 2,
            3, 4, 5, 1
        }
    );
    math4610::matrix<double> upper;
    mat.decompose(&upper, NULL);

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    void decompose(
        matrix* __upper,
        matrix* __lower)
    { // doolittle decomposition algorithm
        if (m_rows != m_cols)
            throw std::runtime_error(
                "non-square matricies not supported");
        size_t size = m_rows;
        matrix upper(size, size);
        matrix lower(size, size);
        for (size_t row = 0; row < size; row++) {
            for (size_t col = 0; col < size; col++) {
                if (col < row) lower.m_data[col * size + row] = 0;
                else {
                    lower.m_data[col * size + row] =
                        m_data[col * size + row];
                    for (size_t ex = 0; ex < row; ex++)
                        lower.m_data[col * size + row] -=
                            lower.m_data[col * size + ex] *
                            upper.m_data[ex * size + row];
                }
            }
            for (size_t col = 0; col < size; col++) {
                if (col < row)       upper.m_data[row * size + col] = 0;
                else if (col == row) upper.m_data[row * size + col] = 1;
                else {
                    upper[row * size + col] =
                        m_data[row * size + col] /
                        lower.m_data[row * size + row];
                    for (size_t ex = 0; ex < row; ex++)
                        upper.m_data[row * size + col] -=
                            (lower.m_data[row * size + ex] *
                            upper.m_data[ex * size + col]) /
                            lower.m_data[row * size + row];
                }
            }
        }
        if (__upper) *__upper = std::move(upper);
        if (__lower) *__lower = std::move(lower);
    }

**Last Modified:** November/2019
