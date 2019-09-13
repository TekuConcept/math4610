/**
 * Created by TekuConcept on September 13, 2019
 */

#include <cmath>
#include <iostream>
#include <functional>

#include "errabs.h"

#define VERBOSE(x) std::cout << x << std::endl


int main() {
    VERBOSE("-- BEGIN --");

    std::function<double(double)> f  =
        [](double x){ return (3 * std::pow(x,3)) + std::pow(x,2) + 5; };
    std::function<double(double)> df =
        [](double x){ return (9 * std::pow(x,2)) + (2 * x); };

    auto x             = 8.0;
    auto h             = 1.0;
    auto dF            = 0.0;
    auto epsilon_error = 1.0;

    for (auto i = 0; i < 1000; i++) {
        dF = (f(x + h) - f(x - h)) / (2 * h);
        auto error = math4610::absolute_error(dF, df(x));
        if (error == 0.0F) break;
        epsilon_error = error;
        VERBOSE("error: " << epsilon_error << "; h = " << h);
        h *= 0.5F;
        if (h == 0) break;
    }

    VERBOSE("f'(x) = ");
    VERBOSE("Approximately: " << dF);
    VERBOSE("Exactly:       " << df(x));

    VERBOSE("-- END OF LINE --");
    return 0;
}
