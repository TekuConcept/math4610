/**
 * Created by TekuConcept on October 12, 2019
 */

#ifndef MATH4610_BISECT_SECANT_H
#define MATH4610_BISECT_SECANT_H

#include "bisect.h"
#include "secant.h"

namespace math4610 {

    template <typename T>
    T
    bisect_secant(
        std::function<T(T)> __f,
        T                   __upper_bound,
        T                   __lower_bound,
        T                   __transition_epsilon = (T)1.0E-2,
        T                   __epsilon = (T)1.0E-5)
    {
        auto x0 = bisection<T>(
            __f,
            __upper_bound,
            __lower_bound,
            /*target=*/0,
            __transition_epsilon);
        return secant<T>(
            __lower_bound,
            x0,
            __f,
            __epsilon);
    }

}

#endif
