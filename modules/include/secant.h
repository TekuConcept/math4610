/**
 * Created by TekuConcept on October 12, 2019
 */

#ifndef MATH4610_SECANT_H
#define MATH4610_SECANT_H

#include <cmath>
#include <functional>

namespace math4610 {

    template <typename T>
    T
    secant(
        T                   __x0,
        T                   __x1,
        std::function<T(T)> __f,
        T                   __epsilon = (T)1.0E-5)
    {
        T h;
        T xi = __x0;
        T xj = __x1;
        size_t limit = 0;
        do {
            auto n1 = __f(xi);
            auto n2 = __f(xj);
            h   = (n2 * (xi - xj)) / (n1 - n2);
            xi  = xj;
            xj -= h;
            limit++;
        } while (std::abs(h) >= __epsilon && limit < 1000);
        return xj;
    }

}

#endif
