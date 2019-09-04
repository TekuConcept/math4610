/**
 * Created by TekuConcept on September 4, 2019
 * Single-Precision Machine Epsilon Computation
 */

#include "smaceps.h"
#include "absolute_error.h"

namespace math4610 {

    void
    single_machine_epsilon(
        double* __epsilon,
        int*    __power_of_two)
    {
        auto one           = 1.0;
        auto epsilon       = 1.0;
        auto epsilon_error = 1.0;
        auto power_of_two  = -1;

        for (auto i = 0; i < 1000; i++) {
            auto next  = one + epsilon;
            auto error = absolute_error(next, one);
            if (error == 0.0) break;
            epsilon_error = error;
            epsilon *= 0.5;
            power_of_two++;
        }

        if (__epsilon)      *__epsilon      = epsilon_error;
        if (__power_of_two) *__power_of_two = power_of_two;
    }

}
