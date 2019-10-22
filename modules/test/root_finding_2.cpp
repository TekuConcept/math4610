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

std::ostream&
operator<<(
    std::ostream& __os,
    std::vector<double> __n)
{
    __os << "[  ";
    for (auto x : __n)
        __os << x << "  ";
    __os << "]";
    return __os;
}


void Task7() {
    auto begin  = 1.1;
    auto end    = 68.3;
    auto slices = 4760; // SUM from i=1 to 69 of (2*i-1)
    auto roots = math4610::multi_bisection<double>(
        [](double x) -> double {
            return std::sin(M_PI * std::pow(x, 2) + 3.7);
        },
        begin,
        end,
        slices
    );
    VERBOSE("Roots: " << roots);
}


void Task8() {
    auto begin  = 1.1;
    auto end    = 68.3;
    auto slices = 4760; // SUM from i=1 to 69 of (2*i-1)
    auto roots = math4610::multi_newton_raphson<double>(
        [](double x) -> double {
            return std::sin(M_PI * std::pow(x, 2) + 3.7);
        },
        [](double x) -> double {
            return 2 * M_PI * x * std::cos(M_PI * std::pow(x, 2) + 3.7);
        },
        begin,
        end,
        slices
    );
    VERBOSE("Roots: " << roots);
}


void Task9() {
    auto begin  = 1.1;
    auto end    = 68.3;
    auto slices = 4760; // SUM from i=1 to 69 of (2*i-1)
    auto roots = math4610::multi_secant<double>(
        [](double x) -> double {
            return std::sin(M_PI * std::pow(x, 2) + 3.7);
        },
        begin,
        end,
        slices
    );
    VERBOSE("Roots: " << roots);
}


int main() {
    VERBOSE("-- BEGIN --");

    Task7();
    Task8();
    Task9();

    VERBOSE("-- END OF LINE --");
    return 0;
}
