/**
 * Created by TekuConcept on September 20, 2019
 */

#ifndef MATH4610_BISECT_H
#define MATH4610_BISECT_H

#include <cmath>
#include <iostream>
#include <functional>

namespace math4610 {

    template <typename T>
    T
    bisection(
        std::function<T(T)> __f,
        T                   __upper_bound,
        T                   __lower_bound,
        T                   __target = (T)0,
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
            std::cout << i << "|"
                << " xu: " << upper_bound
                << " xl: " << lower_bound
                << " xr: " << root
                << "\n";
            if (check < 0)      upper_bound = root;
            else if (check > 0) lower_bound = root;
            else break;
            // safety machanism incase of infinite loop
            if (i++ > 1000) break;
        } while (error >= __epsilon);
        return root;
    }

}

#endif
