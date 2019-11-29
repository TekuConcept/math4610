# Power Iteration

**Routine Name:** power_iteration

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will solve for the greatest eigenvalue in the system.

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
    V('\n' << A.power_iteration());

Example output:

    -12       5       0      -7
      5     -13       4       4
      0       4       7      -1
     -7       4      -1     -12

    [  -13.96  12.81  -2.133  -13.38  ]

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    std::vector<T> power_iteration(
        const std::vector<T> __x          = { },
        size_t               __iterations = 1E3,
        double               __tollerance = 1.0E-8)
    {
        if (m_rows != m_cols)
            throw std::runtime_error(
                "non-square matrices not supported");
        std::vector<T> y = __x;
        y.resize(m_cols);
        if (__x.size() == 0) {
            auto uniform = std::uniform_int_distribution<>{ -10, 10 };
            for (auto& c : y) c = (T)uniform(s_random_engine);
        }
        for (size_t i = 0; i < __iterations; i++) {
            auto n = norm<T>(y, 2);
            auto v = scale(y, 1 / n); // eigenvector
            y = *this * v;
            auto theta = dot<T>(v, y); // eigenvalue
            auto gamma = subtract<T>(y, scale<T>(v, theta));
            auto threshold = std::abs(theta) * __tollerance;
            if (norm<T>(gamma, 2) <= threshold) break;
        }
        return y;
    }

**Last Modified:** November/2019
