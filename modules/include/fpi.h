/**
 * Created by TekuConcept on September 20, 2019
 */

#ifndef MATH4610_FPI_H
#define MATH4610_FPI_H

#include <iostream>
#include <functional>
#include "errapr.h"

namespace math4610 {

    template <typename T>
    bool
    fixed_point_iteration(
        std::function<T(T)> __g,
        T*                  __root,
        T                   __initial,
        T                   __epsilon = (T)1.0E-5)
    {
        T x = __initial;
        for (int i = 0; i < 1000; i++) {
            auto c     = __g(x);
            auto error = approximate_error(c, x);
            std::cout << i << "|"
                << " x: " << x
                << " c: " << c
                << " e: " << error
                << "\n";
            x = c;
            if (std::isinf(c) || std::isnan(c)) return false;
            if ((error == (T)0) || (error < __epsilon)) break;
            if (i == (1000 - 1)) return false; // solution not reached
        }
        if (__root) *__root = x;
        return true;
    }

}

#endif
