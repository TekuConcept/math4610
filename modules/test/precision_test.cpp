/**
 * Created by TekuConcept on September 4, 2019
 */

#include <iostream>

#define VERBOSE(x) std::cout << x << std::endl

/**
 * Absolute error: |x - x*|
 * Relative error: |x - x*| / |x*|
 */

int main() {
    VERBOSE("-- BEGIN --");

    auto one = 1.0;
    auto epsilon = 1.0;

    for (auto i = 0; i < 1000; i++) {
        auto diff = one - (one + epsilon);
        VERBOSE("diff: " << diff << ", epsilon: " << epsilon);
        epsilon *= 0.5;
        if (diff == 0.0) break;
    }

    VERBOSE("-- END OF LINE --");
    return 0;
}
