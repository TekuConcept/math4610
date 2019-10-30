/**
 * Created by TekuConcept on October 30, 2019
 */

#include <cmath>
#include <vector>
#include <algorithm>

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

}