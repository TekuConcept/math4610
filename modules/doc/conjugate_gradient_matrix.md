# Conjugate Gradient

**Routine Name:** conjugate_gradient

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will solve a system of equations using the conjugate gradient metthod. Given an initial estimate, the system will iterate and more closely approximate a solution to the system if one exists following the gradient.

**Input:** The matrix, the target, and an optional initial estimate.

**Output:** The approximated solution to the system.

**Usage/Example:**

Code can be written as follows:

    size_t n = 3;
    auto mat = math4610::matrix<double>::create_random(
        n, -10, 10, true, true);
    std::vector<double> x(n, 1);
    auto b = mat * x;
    auto result = mat.conjugate_gradient(b);
    // compare the result with x

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    std::vector<T> conjugate_gradient(
        const std::vector<T>& __b,
        const std::vector<T>& __x = { },
        double                __tollerance = 1.0E-8)
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
        auto r = subtract(__b, *this * x);
        auto p = r;
        for (size_t c = 0; c < 1E3; c++) {
            auto ap = *this * p;
            auto r2 = dot(r, r);
            auto alpha = r2 / dot(p, ap);
            x = add(x, scale(p, alpha));
            r = subtract(r, scale(ap, alpha));
            auto r_norm = norm<T>(r, 2);
            if (r_norm < __tollerance) break;
            auto beta = dot(r, r) / r2;
            p = add(r, scale(p, beta));
        }
        return x;
    }

**Last Modified:** November/2019
