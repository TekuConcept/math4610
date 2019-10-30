/**
 * Created by TekuConcept on October 30, 2019
 */

#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace math4610 {

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
        return std::pow(sum, 1 / __p);
    }


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
    std::vector<T>
    add(
        const std::vector<T>& __lhs,
        const std::vector<T>& __rhs)
    {
        if (__lhs.size() != __rhs.size())
            throw std::runtime_error(
                "cannot add vectors of different sizes");
        size_t size = __lhs.size();
        std::vector<T> result;
        result.resize(size);
        for (size_t i = 0; i < size; i++)
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
        size_t size = __lhs.size();
        std::vector<T> result;
        result.resize(size);
        for (size_t i = 0; i < size; i++)
            result[i] = __lhs[i] - __rhs[i];
        return result;
    }


    template <typename T>
    std::vector<T>
    scale(
        const std::vector<T>& __v,
        T                     __s)
    {
        size_t size = __v.size();
        std::vector<T> result;
        result.resize(size);
        for (size_t i = 0; i < size; i++)
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
        return norm<T>(difference, __p) / norm<T>(__exact_value);
    }

}
