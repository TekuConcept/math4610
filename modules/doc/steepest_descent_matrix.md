# Steepest Descent

**Routine Name:** steepest_descent

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will solve a system of equations using the method of steepest descent. Given an initial estimate, the system will iterate and more closely approximate a solution to the system if one exists following the gradient.

**Input:** The matrix, the target, and an optional initial estimate.

**Output:** The approximated solution to the system.

**Usage/Example:**

Code can be written as follows:

    size_t n = 3;
    auto mat = math4610::matrix<double>::create_random(
        n, -10, 10, true, true);
    std::vector<double> x(n, 1);
    auto b = mat * x;
    auto result = mat.steepest_descent(b);
    // compare the result with x

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    std::vector<T> steepest_descent(
        const std::vector<T>& __b,
        const std::vector<T>& __x = { })
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
        for (size_t c = 0; c < 1E3; c++) {
            auto r = subtract(__b, *this * x);
            auto a = dot(r, r) / dot(r, *this * r);
            auto z = add(x, scale(r, a));
            if (allclose(x, z, /*rtol=*/0, /*atol=*/1E-10)) break;
            x = std::move(z);
        }
        return x;
    }

**Last Modified:** November/2019
