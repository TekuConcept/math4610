# Inverse Power Iteration

**Routine Name:** inverse_power_iteration

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will solve for the smallest eigenvalue in the system.

**Input:** The matrix describing the system and an optional number of iterations.

**Output:** The eigen vector solution.

**Usage/Example:**

Code can be written as follows:

    auto A = math4610::matrix<double>::create_random(
        /*size=*/4,
        /*lower_bound=*/-10.0,
        /*upper_bound=*/10.0,
        /*symmetric=*/true,
        /*diagonally_dominant=*/true
    );
    A.print();
    V('\n' << A.inverse_power_iteration());

Example output:

     24      -8       7      -9
     -8      16       0      -8
      7       0     -11       4
     -9      -8       4      21

    [ -0.08118 -0.1326 -0.05941 -0.09817 ]

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    std::vector<T> inverse_power_iteration(
        const T              __sigma      = 0,
        const std::vector<T> __x          = { },
        size_t               __iterations = 1E3,
        double               __tollerance = 1.0E-8)
    {
        if (m_rows != m_cols)
            throw std::runtime_error(
                "non-square matrices not supported");
        matrix I = identity(m_rows);
        std::vector<T> y = __x;
        y.resize(m_cols);
        if (__x.size() == 0) {
            auto uniform = std::uniform_int_distribution<>{ -10, 10 };
            for (auto& c : y) c = (T)uniform(s_random_engine);
        }
        for (size_t i = 0; i < __iterations; i++) {
            auto n = norm<T>(y, 2);
            auto v = scale(y, 1 / n);
            auto G = *this - (I * __sigma);
            y = G.rref(v);
            auto theta = dot<T>(v, y);
            auto gamma = subtract<T>(y, scale<T>(v, theta));
            auto threshold = std::abs(theta) * __tollerance;
            if (norm<T>(gamma, 2) <= threshold) break;
        }
        return y;
    }

**Last Modified:** November/2019
