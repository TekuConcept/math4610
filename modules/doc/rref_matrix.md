# Row-Reduced Echelon Form

**Routine Name:** rref

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the row-reduced echelon form of a matrix. The matrix must have the b-vector appended to the last column of the matrix such that the matrix is of size N rows by (N+1) columns.

**Input:** The matrix to process.

**Output:** The row-reduced echelon matrix.

**Usage/Example:**

Code can be written as follows:

    math4610::matrix<double> mat(
        3, 4,
        {
            5, -6, -7,   7, 
            3, -2,  5, -17, 
            2,  4, -3,  29
        }
    );
    auto echelon = mat.rref();
    echelon.print();

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    matrix rref() const
    {
        if ((m_rows + 1) != m_cols)
            throw std::runtime_error("matrix must be N x (N+1)");
        matrix a(m_rows, m_cols, m_data); // copy
        size_t pivot = 0;
        while (pivot < m_rows) {
            for (size_t row = 0; row < m_rows; row++) {
                T denominator = a.m_data[pivot * m_cols + pivot];
                T numerator   =
                    a.m_data[row * m_cols + pivot] / denominator;
                for (size_t col = 0; col < m_cols; col++) {
                    if (row == pivot)
                            a.m_data[row   * m_cols + col] /= denominator;
                    else a.m_data[row   * m_cols + col] -=
                            a.m_data[pivot * m_cols + col] * numerator;
                }
            }
            pivot++;
        }
        return a;
    }

**Last Modified:** November/2019
