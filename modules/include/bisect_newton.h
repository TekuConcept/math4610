/**
 * Created by TekuConcept on October 12, 2019
 */

#ifndef MATH4610_BISECT_NEWTON_H
#define MATH4610_BISECT_NEWTON_H

#include "bisect.h"
#include "newton.h"

namespace math4610 {

    template <typename T>
    T
    bisect_newton(
        std::function<T(T)> __f,
        std::function<T(T)> __df,
        T                   __upper_bound,
        T                   __lower_bound,
        T                   __epsilon = (T)1.0E-5,
        T                   __epsilon_scalar = (T)1.0E3)
    {
        auto x0 = bisection<T>(
            __f,
            __upper_bound,
            __lower_bound,
            /*target=*/0,
            __epsilon * __epsilon_scalar);
        return newton_raphson<T>(
            x0,
            __f,
            __df,
            __epsilon);
    }

}

#endif
