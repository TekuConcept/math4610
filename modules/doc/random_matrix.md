# Random Matrix

**Routine Name:** create_random

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will decompose a matrix into its cholesky-root form, L.

**Input:** The size n for an nxn matrix, an optional lower bound, an optional upper bound, an optional flag for if the matrix is symmetric, and an optional flag for if the matrix is diagonally dominant.

**Output:** The random matrix result.

**Usage/Example:**

Code can be written as follows:

    auto size                   =    4;
    auto lower_bound            =  0.0;
    auto upper_bound            = 10.0;
    auto is_symmetric           = false;
    auto is_diagonally_dominant = true;
    auto result = math4610::matrix<double>::create_random(
        size,
        lower_bound,
        upper_bound,
        is_symmetric,
        is_diagonally_dominant
    );
    result.print();

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    static matrix create_random(
        size_t __size,
        T      __lower_bound = (T)-10.0,
        T      __upper_bound = (T) 10.0,
        bool   __symmetric = false,
        bool   __diagonally_dominant = false)
    {
        if (__size == 0)
            throw std::runtime_error(
                "size must be non-zero");
        else if (__lower_bound == __upper_bound)
            throw std::runtime_error(
                "lower bound cannot be equal to upper bound");
        if (__lower_bound > __upper_bound)
            std::swap(__lower_bound, __upper_bound);
        matrix result(__size, __size);
        auto uniform = std::uniform_real_distribution<>{
            __lower_bound,
            __upper_bound
        };
        auto next = [&uniform]()
        { return uniform(s_random_engine); };
        for (size_t i = 0; i < result.m_data.size(); i++)
            result.m_data[i] = (T)next();
        if (__symmetric)
            _S_make_symmetric(&result);
        if (__diagonally_dominant)
            _S_make_diagonally_dominant(&result);
        return result;
    }

    static inline void _S_make_symmetric(matrix* __mat)
    {
        auto& data = __mat->m_data;
        auto rows  = __mat->m_rows;
        auto cols  = __mat->m_cols;
        size_t n   = std::min(rows, cols);
        for (size_t span = 0; span < n; span++)
            for (size_t offset = span; offset < n; offset++)
                data[span * n + offset] = data[offset * n + span];
    }

    static inline void _S_make_diagonally_dominant(
        matrix* __mat,
        bool    __symmetric,
        T       __lower_bound,
        T       __upper_bound)
    {
        auto& data = __mat->m_data;
        auto rows  = __mat->m_rows;
        auto cols  = __mat->m_cols;
        size_t n = std::min(rows, cols);
        for (size_t y = 0; y < n; y++) {
            if (data[y * cols + y] != 0) continue;
            for (size_t x = 0; x < n; x++) {
                if (x == y) continue;
                auto& m = data[y * cols + x];
                if (m != 0) {
                    std::swap(m, data[y * cols + y]);
                    if (__symmetric) data[x * cols + y] = 0;
                    break;
                }
            }
        }
        for (size_t y = 0; y < n; y++) {
            T sum = 0;
            T a = std::abs(data[y * cols + y]);
            for (size_t x = 0; x < n; x++)
                if (x != y) sum += std::abs(data[y * cols + x]);
            if (a < sum) {
                if (__symmetric) {
                    auto& m = data[y * cols + y];
                    m = sum * (m >= 0 ? 1 : -1);
                }
                else {
                    double delta = (sum - a) / (double)n;
                    for (size_t x = 0; x < n; x++) {
                        if (x == y) continue;
                        auto& m = data[y * cols + x];
                        if (m > 0) m = (T)std::floor(m - delta);
                        else if (m < 0) m = (T)std::floor(m + delta);
                        // else if (m == 0) do no modify
                    }
                }
            }
        }
    }

**Last Modified:** November/2019
