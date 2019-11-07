# Guassian Elimination

**Routine Name:** guass_elimination

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will solve a system of equations using guassian elimination.

**Input:** The matrix describing the system (A) and a vector target (b).

**Output:** The vector solution (x).

**Usage/Example:**

Code can be written as follows:

    math4610::matrix<double> A(
        4, 4,
        {
            1, 2, 3, 4,
            5, 1, 7, 8,
            9, 0, 1, 2,
            3, 4, 5, 1
        }
    );
    std::vector<double> b{ 8, 3, 4, 9 }
    auto solution = A.guass_elimination(b);

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )

    std::vector<T> gauss_elimination(const std::vector<T>& __b) const
    {
        if (m_rows != m_cols)
            throw std::runtime_error(
                "non-square matrices not supported");
        else if (__b.size() != m_rows)
            throw std::runtime_error(
                "matrix and vector dimension mismatch");
        matrix a(m_rows, m_cols, m_data); // copy
        std::vector<T> b = __b; // copy
        std::vector<T> x(__b.size());
        if (!_S_gauss(&a, &b, &x))
            throw std::runtime_error("could not resolve solution");
        return x;
    }

    static bool _S_gauss(
        matrix*         __a,
        std::vector<T>* __b,
        std::vector<T>* __x,
        T               __tollerance = (T)0.0001)
    {
        auto n = __a->m_rows;
        auto& data = __a->m_data;
        std::vector<T> s(n);
        for (size_t i = 0; i < n; i++) {
            s[i] = std::abs(data[i * n + 0]);
            for (int j = 1; j < n; j++)
                if (std::abs(data[i * n + j]) > s[i])
                    s[i] = std::abs(data[i * n + j]);
        }
        bool success = _S_eliminate(__a, &s, __b, __tollerance);
        if (success) _S_substitute(__a, __b, __x);
        return success;
    }

    static bool _S_eliminate(
        matrix*         __a,
        std::vector<T>* __s,
        std::vector<T>* __b,
        T               __tollerance)
    {
        auto n     = __a->m_rows;
        auto& data = __a->m_data;
        auto& b    = *__b;
        auto& s    = *__s;
        for (size_t k = 0; k < (n - 1); k++) {
            _S_pivot(__a, __b, __s, k);
            if (std::abs(data[k * n + k] / s[k]) < __tollerance)
                return false;
            for (size_t i = k + 1; i < n; i++) {
                T factor = data[i * n + k] / data[k * n + k];
                for (size_t j = k + 1; j < n; j++)
                    data[i * n + j] -= factor * data[k * n + j];
                b[i] -= factor * b[k];
            }
        }
        if (std::abs(data[(n - 1) * n + n - 1] /
            s[n - 1]) < __tollerance)
                return false;
        else return true;
    }

    static void _S_pivot(
        matrix*         __a,
        std::vector<T>* __b,
        std::vector<T>* __s,
        size_t          __k)
    {
        auto n     = __a->m_rows;
        auto& data = __a->m_data;
        auto& b    = *__b;
        auto& s    = *__s;
        size_t p   = __k;
        T big      = (T)std::abs(data[__k * (n + 1)] / s[__k]);
        for (size_t ii = __k + 1; ii < n; ii++) {
            T dummy = (T)std::abs(data[ii * n + __k] / s[ii]);
            if (dummy > big) {
                big = dummy;
                p   = ii;
            }
        }
        if (p != __k) {
            for (size_t jj = __k; jj < n; jj++)
                std::swap(data[p * n + jj], data[__k * n + jj]);
            std::swap(b[p], b[__k]);
            std::swap(s[p], s[__k]);
        }
    }

    static void _S_substitute(
        matrix*         __a,
        std::vector<T>* __b,
        std::vector<T>* __x)
    {
        auto n     = __a->m_rows;
        auto& data = __a->m_data;
        auto& b    = *__b;
        auto& x    = *__x;
        x[n - 1] = b[n - 1] / data[n * n - 1];
        for (size_t i = n - 2; i >= 0; i--) {
            T sum = (T)0;
            for (size_t j = i + 1; j < n; j++)
                sum += data[i * n + j] * x[j];
            x[i] = (b[i] - sum) / data[i * (n + 1)];
            if (i == 0) break; // signed break
        }
    }

**Last Modified:** November/2019
