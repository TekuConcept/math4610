/**
 * Created by TekuConcept on September 13, 2019
 */

#include <cmath>
#include <iostream>
#include <functional>

#include "errabs.h"
#include "errrel.h"

#define VERBOSE(x) std::cout << x << std::endl

inline void task6() {
    std::function<double(double)> f  =
        [](double x){ return (3 * std::pow(x,3)) + std::pow(x,2) + 5; };
    std::function<double(double)> df =
        [](double x){ return (9 * std::pow(x,2)) + (2 * x); };

    auto x             = 8;
    auto h             = 1.0;
    auto dF            = 0.0;
    auto epsilon_error = 1.0;

    for (auto i = 0; i < 1000; i++) {
        dF = (f(x + h) - f(x - h)) / (2 * h);
        auto error = math4610::absolute_error(dF, df(x));
        if (error == 0.0F) break;
        epsilon_error = error;
        VERBOSE(
            i <<
            ": f'(x)=" << dF <<
            "; error: " << epsilon_error <<
            "; h = " << h);
        h *= 0.5F;
        if (h == 0) break;
    }

    VERBOSE("");
    VERBOSE("f'(" << x << ") =");
    VERBOSE("Approximately: " << dF);
    VERBOSE("Exactly:       " << df(x));
    VERBOSE("\n\n");
}


inline void task9() {
    std::function<double(double)> f  =
        [](double x){ return std::exp(x); };
    std::function<double(double)> df =
        [](double x){ return std::exp(x); };

    auto x             = M_PI;
    auto h             = 1.0;
    auto dF            = 0.0;
    auto epsilon_error = 0.0;
    auto valid         = false;

    for (auto i = 0; i < 50; i++) {
        dF = (f(x + h) - f(x - h)) / (2 * h);
        auto abs_error = math4610::absolute_error(dF, df(x));
        auto rel_error = math4610::relative_error(dF, df(x));
        if ((abs_error == 0.0F) ||
            (valid && (abs_error > epsilon_error)))
            break;
        VERBOSE(
            i <<
            ": f'(x)=" << dF <<
            "; abs: " << abs_error <<
            "; rel: " << rel_error <<
            "; h = " << h);
        epsilon_error = abs_error;
        h *= 0.5F;
        valid = true;
        if (h == 0) break;
    }

    VERBOSE("");
    VERBOSE("f'(pi) =");
    VERBOSE("Approximately: " << dF);
    VERBOSE("Exactly:       " << df(x));
}


int main() {
    VERBOSE("-- BEGIN --");

    task6();
    task9();

    VERBOSE("-- END OF LINE --");
    return 0;
}
