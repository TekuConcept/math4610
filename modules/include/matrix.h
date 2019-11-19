/**
 * Created by TekuConcept on October 31, 2019
 */

#ifndef MATH4610_MATRIX_H
#define MATH4610_MATRIX_H

#include <cmath>
#include <cstring>

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <type_traits>

#include <omp.h>

#include "vector_ops.h"

namespace math4610 {

    template <typename T>
    class matrix {
    public:
        matrix() : m_rows(0), m_cols(0) { }
        matrix(
            size_t rows,
            size_t cols)
        : m_rows(rows), m_cols(cols)
        { m_data.resize(rows * cols); }
 	    matrix(const matrix& m) = default;
        matrix(
            size_t rows,
            size_t cols,
            void* data)
        : m_rows(rows), m_cols(cols)
        {
            m_data.resize(rows * cols);
            std::memcpy(m_data.data(), data, m_data.size());
        }
        matrix(
            size_t rows,
            size_t cols,
            std::vector<T> data)
        : m_rows(rows), m_cols(cols)
        {
            m_data = data;
            m_data.resize(rows * cols);
        }
        matrix(std::vector<T> data)
        : m_rows(1), m_cols(data.size()), m_data(data)
        { }
     	~matrix() = default;

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
            auto uniform = std::uniform_int_distribution<>{
                (int)__lower_bound,
                (int)__upper_bound
            };
            auto next = [&uniform]()
            { return (T)uniform(s_random_engine); };
            for (size_t i = 0; i < result.m_data.size(); i++)
                result.m_data[i] = (T)next();
            if (__symmetric)
                _S_make_symmetric(&result);
            if (__diagonally_dominant)
                _S_make_diagonally_dominant(
                    &result, __symmetric, __lower_bound, __upper_bound);
            return result;
        }

        T* data() { return m_data.data(); }
        bool empty() { return m_data.size() == 0; }
        size_t rows() const { return m_rows; }
        size_t cols() const { return m_cols; }
        size_t size() const { return m_data.size(); }

        T& at(size_t row, size_t col)
        { return m_data.at(row * m_cols + col); }
        const T& at(size_t row, size_t col) const
        { return m_data.at(row * m_cols + col); }
        T& at (size_t idx)
        { return m_data.at(idx); }
        const T& at(size_t idx) const
        { return m_data.at(idx); }

        T* ptr(size_t row, size_t col)
        { return &m_data[row * m_cols + col]; }
        const T* ptr(size_t row, size_t col) const
        { return &m_data[row * m_cols + col]; }
        T* ptr(size_t idx)
        { return &m_data[idx]; }
        const T* ptr(size_t idx) const
        { return &m_data[idx]; }

        void reshape(
            size_t __rows,
            size_t __cols)
        {
            if ((__rows * __cols) != m_data.size())
                throw std::runtime_error(
                    "new area does not match old area");
            m_rows = __rows;
            m_cols = __cols;
        }

        void resize(
            size_t rows,
            size_t cols)
        { m_data.resize(rows * cols); }

        matrix operator+(const matrix& __right)
        {
            if ((this->m_rows != __right.m_rows) ||
                (this->m_cols != __right.m_cols))
                throw std::runtime_error("matrix dimension mismatch");
            matrix result(this->m_rows, this->m_cols);
            for (size_t i = 0; i < m_data.size(); i++)
                result.m_data[i] = m_data[i] + __right.m_data[i];
            return result;
        }

        matrix operator-(const matrix& __right)
        {
            if ((this->m_rows != __right.m_rows) ||
                (this->m_cols != __right.m_cols))
                throw std::runtime_error("matrix dimension mismatch");
            matrix result(this->m_rows, this->m_cols);
            for (size_t i = 0; i < m_data.size(); i++)
                result.m_data[i] = m_data[i] - __right.m_data[i];
            return result;
        }

        std::vector<T> operator*(const std::vector<T>& __right)
        {
            if (this->m_cols != __right.size())
                throw std::runtime_error("vector-matrix size mismatch");
            std::vector<T> result;
            result.resize(__right.size());
            size_t y;
            for (y = 0; y < m_rows; y++) {
                auto* row = &m_data[y * m_cols];
                result[y] = 0;
                for (size_t x = 0; x < m_cols; x++)
                    result[y] += row[x] * __right[x];
            }
            return result;
        }

        matrix operator*(const matrix& __right)
        {
            if (m_cols != __right.m_rows)
                throw std::runtime_error(
                    "cannot multiply matrices: invalid dimensions");
            matrix result(m_rows, __right.m_cols);
            size_t t = m_cols;
            for (size_t u = 0; u < m_rows; u++) {
                for (size_t v = 0; v < __right.m_cols; v++) {
                    T sum = 0;
                    for (size_t w = 0; w < t; w++)
                        sum += m_data[u * m_cols + w] *
                            __right.m_data[w * __right.m_cols + v];
                    result.m_data[u * result.m_cols + v] = sum;
                }
            }
            return result;
        }

        void print() const
        {
            for (size_t row = 0; row < m_rows; row++) {
                for (size_t col = 0; col < m_cols; col++) {
                    std::cout << std::setprecision(4) << std::setw(7);
                    std::cout << m_data[row * m_cols + col] << " ";
                }
                std::cout << std::endl;
            }
        }

        bool is_symmetric() const
        {
            if (m_rows != m_cols) return false;
            size_t n = m_rows;
            for (size_t span = 0; span < n; span++)
                for (size_t offset = span; offset < n; offset++)
                    if (m_data[span * n + offset] !=
                        m_data[offset * n + span])
                        return false;
            return true;
        }

        matrix diagonal() const
        {
            matrix result(m_rows, m_cols);
            auto n = std::min(m_rows, m_cols);
            for (size_t i = 0; i < n; i++)
                result.m_data[i * m_cols + i] = m_data[i * m_cols + i];
            return result;
        }

        matrix transpose() const
        {
            matrix result(m_cols, m_rows);
            for (size_t u = 0; u < m_rows; u++)
                for (size_t v = 0; v < m_cols; v++)
                    result.m_data[v * result.m_cols + u] =
                        m_data[u * m_cols + v];
            return result;
        }

        matrix inverse(T __tollerance = (T)1.0E-4) const
        {
            if (m_rows != m_cols)
                throw std::runtime_error(
                    "non-square matrices not supported");

            size_t n = m_rows;
            std::vector<size_t> indices(n);
            std::vector<T> s(n);
            std::vector<T> b(n);
            std::vector<T> x(n);
            matrix result(n, n);

            if (!_M_inverter_decompose(__tollerance, &indices, &s))
                throw std::runtime_error("ill-conditioned system");
            for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++)
                    b[j] = (i == j) ? 1 : 0;
                _M_inverter_substitute(indices, &b, &x);
                for (size_t j = 0; j < n; j++)
                    result.m_data[j * n + i] = x[j];
            }

            return result;
        }

        void lu_decompose(
            matrix* __upper,
            matrix* __lower) const
        { // doolittle decomposition algorithm
            if (m_rows != m_cols)
                throw std::runtime_error(
                    "non-square matrices not supported");
            size_t size = m_rows;
            matrix upper(size, size);
            matrix lower(size, size);
            for (size_t row = 0; row < size; row++) {
                size_t col;
                #pragma omp parallel for
                for (col = 0; col < size; col++) {
                    if (col < row) lower.m_data[col * size + row] = 0;
                    else {
                        lower.m_data[col * size + row] =
                            m_data[col * size + row];
                        for (size_t ex = 0; ex < row; ex++)
                            lower.m_data[col * size + row] -=
                                lower.m_data[col * size + ex] *
                                upper.m_data[ex * size + row];
                    }
                }
                #pragma omp parallel for
                for (col = 0; col < size; col++) {
                    if (col < row)       upper.m_data[row * size + col] = 0;
                    else if (col == row) upper.m_data[row * size + col] = 1;
                    else {
                        upper.m_data[row * size + col] =
                            m_data[row * size + col] /
                            lower.m_data[row * size + row];
                        for (size_t ex = 0; ex < row; ex++)
                            upper.m_data[row * size + col] -=
                                (lower.m_data[row * size + ex] *
                                upper.m_data[ex * size + col]) /
                                lower.m_data[row * size + row];
                    }
                }
            }
            if (__upper) *__upper = std::move(upper);
            if (__lower) *__lower = std::move(lower);
        }

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

        T determinant() const
        { // runs in O(n) time where 'n' represents every coefficient
            if (m_rows != m_cols)
                throw std::runtime_error(
                    "non-square matrices not supported");
            if (m_rows == 0) return 0;
            if (m_rows == 1) return m_data.front();
            struct meta {
                T det;
                int sign;
                size_t width;
                size_t index;
                std::vector<size_t> indices;
            };
            std::vector<meta> layers;
            T det;
            {
                meta root;
                root.det   = 0;
                root.sign  = 1;
                root.width = m_rows;
                root.index = 0;
                root.indices.reserve(root.width);
                for (size_t i = 0; i < root.width; i++)
                    root.indices.push_back(i);
                layers.push_back(root);
            }
            do {
                while (layers.back().width != 2) {
                    const auto& last = layers.back();
                    meta next;
                    next.det = 0;
                    next.sign = 1;
                    next.width = last.width - 1;
                    next.index = 0;
                    next.indices.reserve(next.width);
                    for (size_t i = 0; i < last.width; i++)
                        if (i != last.index)
                            next.indices.push_back(last.indices[i]);
                    layers.push_back(next);
                }
                auto& current = layers.back();
                if (current.width == 2) {
                    size_t r1 = (m_rows - current.width + 0) * m_cols;
                    size_t r2 = (m_rows - current.width + 1) * m_cols;
                    det =
                        m_data[r1 + current.indices[0]] *
                        m_data[r2 + current.indices[1]] -
                        m_data[r1 + current.indices[1]] *
                        m_data[r2 + current.indices[0]];
                }
                else det = current.det;
                layers.pop_back();
                edge: // mild loop hack
                if (!layers.empty()) {
                    auto& parent = layers.back();
                    auto r = (m_rows - parent.width) * m_cols;
                    auto a = m_data[r + parent.indices[parent.index]];
                    parent.det += a * det * parent.sign;
                    parent.index++;
                    parent.sign = -parent.sign;
                    if (parent.index == parent.width) {
                        det = parent.det;
                        layers.pop_back();
                        goto edge;
                    }
                }
            } while (!layers.empty());
            return det;
        }

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

        std::vector<T> rref(const std::vector<T>& __b) const
        {
            if (m_rows != m_cols)
                throw std::runtime_error(
                    "non-square matrix not supported");
            else if (__b.size() != m_rows)
                throw std::runtime_error(
                    "vector-matrix size mismatch");
            matrix a(m_rows, m_cols, m_data); // copy
            std::vector<T> x(__b);
            size_t pivot = 0;
            while (pivot < m_rows) {
                for (size_t row = 0; row < m_rows; row++) {
                    T denominator = a.m_data[pivot * m_cols + pivot];
                    T numerator   =
                        a.m_data[row * m_cols + pivot] / denominator;
                    for (size_t col = 0; col <= m_cols; col++) {
                        if (row == pivot) {
                            if (col == m_cols)
                                x[row] /= denominator;
                            else a.m_data[row * m_cols + col] /= denominator;
                        }
                        else {
                            if (col == m_cols)
                                x[row] -= x[pivot] * numerator;
                            else a.m_data[row * m_cols + col] -=
                                a.m_data[pivot * m_cols + col] * numerator;
                        }
                    }
                }
                pivot++;
            }
            return x;
        }

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
                // r_(i+1) = r_i - a_i*r_i
                auto r = subtract(__b, *this * x);
                auto a = dot(r, r) / dot(r, *this * r);
                auto z = add(x, scale(r, a));
                if (allclose(x, z, /*rtol=*/0, /*atol=*/1E-10)) break;
                x = std::move(z);
            }
            return x;
        }

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

        std::vector<T> lu_solver(const std::vector<T>& __b) const
        {
            matrix upper, lower;
            lu_decompose(&upper, &lower);
            auto y = lower.rref(__b);
            return upper.rref(y);
        }

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
                x[p] = __b[p] / a; // TODO: check div-by-0?
            }
            return x;
        }

        std::vector<T> jacobi_solver(
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
            auto D = this->diagonal();
            auto R = (*this) - D;
            for (size_t c = 0; c < 1E3; c++) {
                std::vector<T> z = subtract(__b, R * x);
                for (size_t i = 0; i < x.size(); i++)
                    z[i] /= D.m_data[i * n + i];
                if (allclose<T>(x, z, /*rtol=*/0, /*atol=*/1E-10)) break;
                x = std::move(z);
            }
            return x;
        }

        std::vector<T> seidel_solver(
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
                std::vector<T> z(n);
                for (size_t j = 0; j < n; j++) {
                    auto d = __b[j];
                    for (size_t i = 0; i < n; i++) {
                        if (i == j) continue;
                        d -= m_data[j * n + i] * x[i];
                        z[j] = d / m_data[j * n + j];
                    }
                }
                if (allclose<T>(x, z, /*rtol=*/0, /*atol=*/1E-10)) break;
                x = std::move(z);
            }
            return x;
        }

    private:
        size_t m_rows;
        size_t m_cols;
        std::vector<T> m_data;

        static std::random_device s_random_device;
        static std::mt19937 s_random_engine;

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

        void _M_inverter_pivot(
            std::vector<size_t>*  __indices,
            const std::vector<T>& __s,
            size_t                __k) const
        {
            auto n = m_rows;
            auto& o = *__indices;
            auto p = __k;
            auto big = std::abs(m_data[o[__k] * n + __k] / __s[o[__k]]);
            for (size_t ii = (__k + 1); ii < n; ii++) {
                auto temp = std::abs(m_data[o[ii] * n + __k] / __s[o[ii]]);
                if (temp > big) {
                    big = temp;
                    p = ii;
                }
            }
            std::swap(o[p], o[__k]);
        }

        // _M_inverter_substitute(indices, b, x);
        void _M_inverter_substitute(
            const std::vector<size_t>& __indices,
            std::vector<T>*            __b,
            std::vector<T>*            __x) const
        {
            auto n = m_rows;
            auto& b = *__b;
            auto& x = *__x;
            auto& o = __indices;
            for (size_t i = 1; i < n; i++) {
                auto sum = b[o[i]];
                for (size_t j = 0; j <= (i - 1); j++)
                    sum -= m_data[o[i] * n + j] * b[o[j]];
                b[o[i]] = sum;
            }
            x[n - 1] = b[o[n - 1]] / m_data[o[n - 1] * n + (n - 1)];
            for (size_t i = n - 2; i >= 0; i--) {
                T sum = 0;
                for (size_t j = i + 1; j < n; j++)
                    sum += m_data[o[i] * n + j] * x[j];
                x[i] = (b[o[i]] - sum) / m_data[o[i] * + i];
                if (i == 0) break;
            }
        }

        bool _M_inverter_decompose(
            T __tollerance,
            std::vector<size_t>* __indices,
            std::vector<T>*      __s) const
        {
            auto n = m_rows;
            auto& o = *__indices;
            auto& s = *__s;
            for (size_t i = 0; i < n; i++) {
                o[i] = i;
                s[i] = std::abs(m_data[i * n]);
                for (int j = 1; j < n; j++)
                    if (std::abs(m_data[i * n + j]) > s[i])
                        s[i] = std::abs(m_data[i * n + j]);
            }
            for (size_t k = 0; k < (n - 1); k++) {
                _M_inverter_pivot(__indices, s, k);
                if (std::abs(m_data[o[k] * n + k] / s[o[k]]) < __tollerance)
                    return false;
                for (size_t i = (k + 1); i < n; i++) {
                    auto factor = m_data[o[i] * n + k] / m_data[o[k] * + k];
                    m_data[o[i] * n + k] = factor;
                    for (size_t j = (k + 1); j < n; j++)
                        m_data[o[i] * n + j] -= factor * m_data[o[k] * n + j];
                }
            }
            return true;
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
    };


    template <typename T>
    std::random_device matrix<T>::s_random_device;
    template <typename T>
    std::mt19937 matrix<T>::s_random_engine(matrix<T>::s_random_device());

}

#endif
