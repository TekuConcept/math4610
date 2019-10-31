/**
 * Created by TekuConcept on October 31, 2019
 */

#ifndef MATH4610_MATRIX_H
#define MATH4610_MATRIX_H

#include <cstring>
#include <vector>

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
 	    matrix(const matrix& m) = default
        matrix(
            size_t rows,
            size_t cols,
            void* data)
        : m_rows(rows), m_cols(cols)
        {
            m_data.resize(rows * cols);
            std::memcpy(m_data.data(), data, m_data.size());
        }
     	~matrix() = default

        std::vector<T>& data() { return m_data; }
        bool empty() { return m_data.size() == 0; }
        size_t rows() const { return m_rows; }
        size_t cols() const { return m_cols; }
        size_t size() const { return m_data.size(); }

        T& at(size_t row, size_t col)
        { return m_data.at(row * m_col + col); }
        const T& at(size_t row, size_t col) const
        { return m_data.at(row * m_col + col); }
        T& at (size_t idx)
        { return m_data.at(idx); }
        const T& at(size_t idx) const
        { return m_data.at(idx); }

        T* ptr(size_t row, size_t col)
        { return &m_data[row * m_col + col]; }
        const T* ptr(size_t row, size_t col) const
        { return &m_data[row * m_col + col]; }
        T* ptr(size_t idx)
        { return &m_data[idx]; }
        const T* ptr(size_t idx) const
        { return &m_data[idx]; }

        void resize(
            size_t rows,
            size_t cols)
        { m_data.resize(rows * cols); }

    private:
        size_t m_rows;
        size_t m_cols;
        std::vector<T> m_data;
    };

}

#endif
