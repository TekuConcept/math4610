/**
 * Created by TekuConcept on September 20, 2019
 */

#include <cmath>
#include <iostream>
#include "fpi.h"
#include "bisect.h"

#define VERBOSE(x) std::cout << x << std::endl

void Task3() {
    bool success;
    double root;
    const double INITIAL = 0.8;

    // f(x) = xcosh(x) + x^3 - pi
    //      = xexp(-x)/2 + xexp(x)/2 + x^3 - pi
    //      = 0
    // root = 1.09633...

    success = math4610::fixed_point_iteration<double>(
        [](double x) -> double {
            return (x * std::cosh(x) + std::pow(x, 3) - M_PI) + x;                        // diverges to -inf
            // return (M_PI - std::pow(x,3)) / std::cosh(x);                              // oscillating
            // return (M_PI - (x * std::cosh(x))) / std::pow(x, 2);                       // diverges to -inf
            // return std::acosh((M_PI - std::pow(x, 3)) / x);                            // does not resolve
            // return 2 * (M_PI - std::pow(x,3) - (x * std::exp(x) / 2)) / std::exp(-x);  // oscillating
            // return 2 * (M_PI - std::pow(x, 3) - (x * std::exp(-x) / 2)) / std::exp(x); // oscillating
            // return -std::log(2 * (M_PI - std::pow(x, 3) - (x * std::exp(x) / 2)) / x); // does not resolve
            // return std::log(2 * (M_PI - std::pow(x, 3) - (x * std::exp(-x) / 2)) / x); // does not resolve
        },
        &root, INITIAL
    );

    if (success) VERBOSE("Root: " << root);
    else VERBOSE("attemp failed");
}

void Task4() {
    auto upper_bound = 1.5;
    auto lower_bound = 0.5;
    auto root = math4610::bisection<double>(
        [](double x) -> double {
            return x * std::cosh(x) + std::pow(x, 3);
        },
        upper_bound,
        lower_bound,
        M_PI
    );
    VERBOSE("Root: " << root);
}

int main() {
    VERBOSE("-- BEGIN --");

    Task3();
    Task4();

    VERBOSE("-- END OF LINE --");
    return 0;
}
