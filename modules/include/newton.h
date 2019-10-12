/**
 * Created by TekuConcept on October 12, 2019
 */

#ifndef MATH4610_NEWTON_H
#define MATH4610_NEWTON_H

#include <cmath>
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
