# Cholesky Factorization

**Routine Name:** cholesky_decompose

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will decompose a matrix into its cholesky-root form, L.

**Input:** The matrix to decompose.

**Output:** The lower triangular cholesky-root matrix.

**Usage/Example:**

Code can be written as follows:

    math4610::matrix<double> mat{
        3, 3,
        {
              4,  12, -16,
             12,  37, -43,
            -16, -43,  98
        }
    };
    auto L = mat.cholesky_decompose();

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    matrix cholesky_decompose() const
    {
        if (!is_symmetric())
            throw std::runtime_error("matrix must be symmetric");
        auto n = m_rows;
        matrix lower(n, n);
        for (size_t k = 0; k < n; k++) {
            for (size_t i = 0; i <= k; i++) {
                auto a = m_data[k * n + i];
                auto s = 0;
                if (k == i) {
                    if (k != 0)
                        for (size_t j = 0; j <= (k - 1); j++)
                            s += std::pow(lower.m_data[k * n + j], 2);
                    lower.m_data[k * n + k] = std::sqrt(a - s); // a >= s
                }
                else {
                    if (i != 0)
                        for (size_t j = 0; j <= (i - 1); j++)
                            s += lower.m_data[i * n + j] *
                                lower.m_data[k * n + j];
                    lower.m_data[k * n + i] = (a - s) /
                        lower.m_data[i * n + i]; // l_ii != 0
                }
            }
        }
        return lower;
    }

**Last Modified:** November/2019
