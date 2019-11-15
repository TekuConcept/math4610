# Jacobi Solver

**Routine Name:** jacobi_solver

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will solve a system of equations using a Jacobian approximation. Given an initial estimate, the system will iterate and more closely approximate a solution to the system if one exists.

**Input:** The matrix, the target, and an optional initial estimate.

**Output:** The approximated solution to the system.

**Usage/Example:**

Code can be written as follows:

    math4610::matrix<double> mat{
        4, 4,
        {
            10, -1,  2,  0,
            -1, 11, -1,  3,
             2, -1, 10, -1,
             0,  3, -1,  8
        }
    };
    std::vector<double> b{ 6, 25, 11, 15 };
    auto x = mat.jacobi_solver(b);

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    std::vector<T> jacobi_solver(
        const std::vector<T>& __b,
        const std::vector<T>& __x = { }) const
    {
        if (m_rows != m_cols)
            throw std::runtime_error(
                "non-square matrices not supported");
        if (m_rows != __b.size())
            throw std::runtime_error(
                "matrix-vector size mismatch");
        auto n = m_rows;
        std::vector<T> x = __x;
        if (x.size() != n) x.resize(n);
        auto D = this->diagonal();
        auto R = (*this) - D;
        for (size_t c = 0; c < 1E3; c++) {
            std::vector<T> z = _S_subtract(__b, R * x);
            for (size_t i = 0; i < x.size(); i++)
                z[i] /= D.m_data[i * n + i];
            if (_S_allclose(x, z, /*rtol=*/0, /*atol=*/1E-10)) break;
            x = std::move(z);
        }
        return x;
    }

**Last Modified:** November/2019
