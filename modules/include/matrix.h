/**
 * Created by TekuConcept on October 31, 2019
 */

#ifndef MATH4610_MATRIX_H
#define MATH4610_MATRIX_H

#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

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
     	~matrix() = default;

        std::vector<T>& data() { return m_data; }
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

        void resize(
            size_t rows,
            size_t cols)
        { m_data.resize(rows * cols); }

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

        void decompose(
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
                for (size_t col = 0; col < size; col++) {
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
                for (size_t col = 0; col < size; col++) {
                    if (col < row)       upper.m_data[row * size + col] = 0;
                    else if (col == row) upper.m_data[row * size + col] = 1;
                    else {
                        upper[row * size + col] =
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

    private:
        size_t m_rows;
        size_t m_cols;
        std::vector<T> m_data;
    };

}

#endif
