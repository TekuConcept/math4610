/**
 * Created by TekuConcept on September 4, 2019
 * Double-Precision Machine Epsilon Computation
 */

#include "dmaceps.h"
#include "errabs.h"

namespace math4610 {
    
    void
    double_machine_epsilon(
        double* __epsilon,
        int*    __exponent)
    {
        auto one           = 1.0;
        auto epsilon       = 1.0;
        auto epsilon_error = 1.0;
        auto exponent      = -1;

        for (auto i = 0; i < 1000; i++) {
            auto next  = one + epsilon;
            auto error = absolute_error(next, one);
            if (error == 0.0) break;
            epsilon_error = error;
            epsilon *= 0.5;
            exponent++;
        }

        if (__epsilon)  *__epsilon  = epsilon_error;
        if (__exponent) *__exponent = exponent;
    }
}
