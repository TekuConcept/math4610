/**
 * Created by TekuConcept on October 12, 2019
 */

#ifndef MATH4610_NEWTON_H
#define MATH4610_NEWTON_H

#include <cmath>
#include <algorithm>
#include <functional>

namespace math4610 {

    
    template <typename T>
    T
    newton_raphson(
        T                   __x0,
        std::function<T(T)> __f,
        std::function<T(T)> __df,
        T                   __epsilon = (T)1.0E-5)
    {
        T h, x = __x0;
        size_t limit = 0;
        do {
            h = __f(x) / __df(x);
            x -= h;
            limit++;
        } while (std::abs(h) >= __epsilon && limit < 1000);
        return x;
    }


    template <typename T>
    std::vector<T>
    multi_newton_raphson(
        std::function<T(T)> __f,
        std::function<T(T)> __df,
        T                   __begin,
        T                   __end,
        unsigned int        __slices  = 100,
        T                   __epsilon = (T)1.0E-5)
    {
        if ((__slices == 0) || (__begin == __end)) return { };
        if (__end < __begin) std::swap(__end, __begin);

        std::vector<T> roots;
        std::vector<std::pair<T,T>> intervals;
        auto delta = (__end - __begin) / __slices;
        auto sign_check = [](T x) -> int {
            if (x >= 0) return 1;
            else if (x < 0) return -1;
        };

        // generate intervals with roots
        auto last_pair  = std::make_pair<T,T>((T)__begin, __f(__begin));
        auto last_check = sign_check(last_pair.second);
        for (auto x = __begin + delta; x <= __end; x += delta) {
            auto next_pair  = std::make_pair<T,T>((T)x, __f(x));
            auto next_check = sign_check(next_pair.second);
            if (next_check != last_check) {
                if (last_pair.second < next_pair.second)
                    intervals.push_back(std::make_pair<T,T>
                    ((T)next_pair.first, (T)last_pair.first));
                else intervals.push_back(std::make_pair<T,T>
                    ((T)last_pair.first, (T)next_pair.first));
            }
            last_pair  = next_pair;
            last_check = next_check;
        }

        // find roots
        for (auto& interval : intervals)
            roots.push_back(newton_raphson<T>(
                (interval.first + interval.second) / 2,
                __f,
                __df,
                __epsilon));

        return roots;
    }


    template <typename T>
    bool
    newton_raphson_converges(
        T                   __x,
        std::function<T(T)> __f,
        std::function<T(T)> __df,
        std::function<T(T)> __ddf)
    {
        auto n1 = __f(__x) * __ddf(__x);
        auto n2 = __df(__x);
        return (std::abs(n1) / std::abs(n2 * n2)) < 1;
    }

}

#endif
