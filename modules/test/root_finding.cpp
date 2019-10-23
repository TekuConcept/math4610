/**
 * Created by TekuConcept on September 20, 2019
 */

#include <cmath>
#include <iostream>
#include "fpi.h"
#include "bisect.h"
#include "newton.h"
#include "secant.h"

#define VERBOSE(x) std::cout << x << std::endl

void Tasksheet2_Task3() {
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

void Tasksheet2_Task4() {
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

void Tasksheet3_Task3_Part1() {
    const double INITIAL = 0.8;
    auto root = math4610::newton_raphson<double>(
        INITIAL,
        [](double x) -> double {
            return x * std::cosh(x) + std::pow(x, 3) - M_PI;
        },
        [](double x) -> double {
            return x * (3 * x + std::sinh(x)) + std::cosh(x);
        }
    );
    VERBOSE("Root: " << root);
}

void Tasksheet3_Task3_Part2() {
    const double FIRST_INITIAL = 0.8;
    const double SECOND_INITIAL = 1.0;
    auto root = math4610::secant<double>(
        FIRST_INITIAL,
        SECOND_INITIAL,
        [](double x) -> double {
            return x * std::cosh(x) + std::pow(x, 3) - M_PI;
        }
    );
    VERBOSE("Root: " << root);
}

int main() {
    VERBOSE("-- BEGIN --");

    Tasksheet2_Task3();
    Tasksheet2_Task4();
    Tasksheet3_Task3_Part1();
    Tasksheet3_Task3_Part2();

    VERBOSE("-- END OF LINE --");
    return 0;
}
