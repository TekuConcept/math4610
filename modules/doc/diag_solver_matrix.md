# Diagonal Solver

**Routine Name:** diagonal_solver

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will solve a system of equations assuming the matrix is diagonal. Each equation assumes the role `ax = b`; thefore `x = b / a`, where `a` is a coefficient along the diagonal, and `b` is given.

**Input:** The matrix and the target.

**Output:** The solution to the system.

**Usage/Example:**

Code can be written as follows:

    math4610::matrix<double> mat2(
        3, 3,
        {
            5,  0,  0,
            0, -2,  0,
            0,  0, -3
        }
    );
    std::vector<double> b{ 7, -17, 29 };
    auto x = mat.diagonal_solver(b);

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    std::vector<T> diagonal_solver(const std::vector<T>& __b) const
    {
        if (m_rows != m_cols)
            throw std::runtime_error(
                "non-square matrices not supported");
        else if (m_rows != __b.size())
            throw std::runtime_error(
                "vector-matrix size mismatch");
        auto n = m_rows;
        std::vector<T> x(n);
        for (auto p = 0; p < n; p++) {
            auto a = m_data[p * n + p];
            x[p] = __b[p] / a;
        }
        return x;
    }

**Last Modified:** November/2019
