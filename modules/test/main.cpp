/**
 * Created by TekuConcept on September 4, 2019
 */

#include <cmath>
#include <iostream>
#include "smaceps.h"

#define VERBOSE(x) std::cout << x << std::endl

int main() {
    VERBOSE("-- BEGIN --");

    float epsilon;
    int exponent;

    math4610::single_machine_epsilon(&epsilon, &exponent);

    auto power_of_two = 1.0 / std::pow(2.0, (exponent + 1));

    VERBOSE("Output from single_machine_epsilon:");
    VERBOSE(power_of_two << "\t" << exponent);

    VERBOSE("-- END OF LINE --");
    return 0;
}
