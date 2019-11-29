/**
 * Created by TekuConcept on October 30, 2019
 */

#ifndef MATH4610_VECTOR_OPS_H
#define MATH4610_VECTOR_OPS_H

#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include <omp.h>

// #include "matrix.h"

namespace math4610 {

    template <typename T>
    T
    infinite_norm(const std::vector<T>& __v)
    {
        // ||x||inf = max(|x_1|,...,|x_n|)
        if (__v.size() == 0) return (T)0;
        auto result = __v.front();
        for (size_t i = 0; i < __v.size(); i++)
            result = std::max(result, __v[i]);
        return result;
    }


    template <typename T>
    T
    norm(
        const std::vector<T>& __v,
        size_t                __p)
    {
        // ||x||p = (sum from i=1 to n of |x_i|^p)^(1/p)
        if (__p == 0) return infinite_norm(__v);
        if (__v.size() == 0) return (T)0;
        T sum = 0;
        for (const auto& x : __v)
            sum += std::pow(x, __p);
        return std::pow(sum, 1.0 / __p);
    }


    template <typename T>
    bool
    allclose(
        std::vector<T> __a,
        std::vector<T> __b,
        T              __relative_error = (T)1E-3,
        T              __absolute_error = (T)1E-3)
    {
        if (__a.size() != __b.size()) return false;
        for (size_t i = 0; i < __a.size(); i++)
            if (std::abs(__a[i] - __b[i]) >
                (__absolute_error + __relative_error * std::abs(__b[i])))
                return false;
        return true;
    }


    template <typename T>
    std::vector<T>
    add(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size())
            throw std::runtime_error(
                "cannot add vectors of different sizes");
        std::vector<T> result;
        result.resize(__lhs.size());
        for (size_t i = 0; i < result.size(); i++)
            result[i] = __lhs[i] + __rhs[i];
        return result;
    }


    template <typename T>
    std::vector<T>
    subtract(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size())
            throw std::runtime_error(
                "cannot subtract vectors of different sizes");
        std::vector<T> result;
        result.resize(__lhs.size());
        for (size_t i = 0; i < result.size(); i++)
            result[i] = __lhs[i] - __rhs[i];
        return result;
    }


    template <typename T>
    std::vector<T>
    scale(
        const std::vector<T>& __v,
        T                     __s)
    {
        std::vector<T> result;
        result.resize(__v.size());
        for (size_t i = 0; i < result.size(); i++)
            result[i] = __s * __v[i];
        return result;
    }


    template <typename T>
    T
    dot(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size())
            throw std::runtime_error(
                "cannot dot vectors of different sizes");
        T result = (T)0;
        size_t size = __lhs.size();
        for (size_t i = 0; i < size; i++)
            result += __lhs[i] * __rhs[i];
        return result;
    }


    template <typename T>
    std::vector<T>
    cross(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size() && __lhs.size() != 3)
            throw std::runtime_error("cannot cross vectors");
        return {
            __lhs[1] * __rhs[2] - __lhs[2] * __rhs[1],
            __lhs[2] * __rhs[0] - __lhs[0] * __rhs[2],
            __lhs[0] * __rhs[1] - __lhs[1] * __rhs[0]
        };
    }


    template <typename T>
    std::vector<T>
    saxpy(
        T                    __a,
        const std::vector<T> __x,
        const std::vector<T> __y)
    {
        if (__x.size() != __y.size())
            throw std::runtime_error(
                "cannot run against vectors of different sizes");
        std::vector<T> result;
        result.resize(__x.size());
        for (size_t i = 0; i < result.size(); i++)
            result[i] = __a * __x[i] + __y[i];
        return result;
    }


    // template <typename T>
    // std::vector<T>
    // multiply(
    //     const matrix<T>&      __A,
    //     const std::vector<T>& __v)
    // {
    //     if (__A.cols() != __v.size())
    //         throw std::runtime_error(
    //             "vector and matrix sizes do not match");
    //     std::vector<T> result;
    //     result.resize(__A.rows());
    //     size_t y;
    //     #pragma omp parallel for
    //     for (y = 0; y < __A.rows(); y++) {
    //         auto* row = __A.at(y, 0);
    //         result[y] = 0;
    //         for (size_t x = 0; x < __A.cols(); x++)
    //             result[y] += row[x] * __v[x];
    //     }
    //     return result;
    // }


    template <typename T>
    inline T
    absolute_error(
        std::vector<T> __approximate_vector,
        std::vector<T> __exact_vector,
        size_t         __p = 0)
    {
        auto difference = subtract<T>(
            __approximate_vector,
            __exact_vector);
        return norm<T>(difference, __p);
    }


    template <typename T>
    inline T
    relative_error(
        std::vector<T> __approximate_vector,
        std::vector<T> __exact_vector,
        size_t         __p = 0)
    {
        auto difference = subtract<T>(
            __approximate_vector,
            __exact_vector);
        return norm<T>(difference, __p) / norm<T>(__exact_vector, __p);
    }

}

#endif
