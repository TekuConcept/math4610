/**
 * Created by TekuConcept on September 4, 2019
 */

#ifndef MATH4610_ERRREL_H_
#define MATH4610_ERRREL_H_

#include <cmath>

namespace math4610 {

    template <typename T>
    inline double relative_error(
        T __approximate_value,
        T __exact_value)
    {
        return std::abs(__approximate_value - __exact_value) /
            std::abs(__exact_value);
    }

}

#endif
