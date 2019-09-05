/**
 * Created by TekuConcept on September 4, 2019
 * Single-Precision Machine Epsilon Computation
 */

#include "smaceps.h"
#include "errabs.h"

namespace math4610 {

    void
    single_machine_epsilon(
        float* __epsilon,
        int*   __exponent)
    {
        auto one           = 1.0F;
        auto epsilon       = 1.0F;
        auto epsilon_error = 1.0F;
        auto exponent      = -1;

        for (auto i = 0; i < 1000; i++) {
            auto next  = one + epsilon;
            auto error = absolute_error(next, one);
            if (error == 0.0F) break;
            epsilon_error = error;
            epsilon *= 0.5F;
            exponent++;
        }

        if (__epsilon)  *__epsilon  = epsilon_error;
        if (__exponent) *__exponent = exponent;
    }

}
