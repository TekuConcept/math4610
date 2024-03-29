/**
 * Created by TekuConcept on September 20, 2019
 */

#ifndef MATH4610_BISECT_H
#define MATH4610_BISECT_H

#include <cmath>
#include <utility>
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

namespace math4610 {

    template <typename T>
    T
    bisection(
        std::function<T(T)> __f,
        T                   __upper_bound,
        T                   __lower_bound,
        T                   __target  = (T)0,
        T                   __epsilon = (T)1.0E-5)
    {
        auto g        = [&](T x) -> T { return __f(x) - __target; };
        T upper_bound = __upper_bound;
        T lower_bound = __lower_bound;
        T root, error = (T)0.0;
        size_t i = 0;
        do {
            root        = (lower_bound + upper_bound) / 2;
            auto g_root = g(root);
            error       = std::abs(g_root);
            auto check  = g(lower_bound) * g_root;
            // std::cout << i << "|"
            //     << " xu: " << upper_bound
            //     << " xl: " << lower_bound
            //     << " xr: " << root
            //     << "\n";
            if (check < 0)      upper_bound = root;
            else if (check > 0) lower_bound = root;
            else break;
            // safety machanism incase of infinite loop
            if (i++ > 1000) break;
        } while (error >= __epsilon);
        return root;
    }


    template <typename T>
    std::vector<T>
    multi_bisection(
        std::function<T(T)> __f,
        T                   __begin,
        T                   __end,
        unsigned int        __slices  = 100,
        T                   __target  = (T)0,
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
            roots.push_back(bisection<T>(
                __f,
                interval.first,
                interval.second,
                __target,
                __epsilon));

        return roots;
    }

}

#endif
