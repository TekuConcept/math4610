/**
 * Created by TekuConcept on November 5, 2019
 */

#include <iostream>

#define V(x) std::cout << x << std::endl

#include "matrix.h"

int main() {
    V("- BEGIN -");

    math4610::matrix<double> mat(
        4, 4,
        {
            1, 2, 3, 4,
            5, 1, 7, 8,
            9, 0, 1, 2,
            3, 4, 5, 1
        }
    );

    V(mat.determinant());

    V("- END OF LINE -");
    return 0;
}
