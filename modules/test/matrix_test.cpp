/**
 * Created by TekuConcept on November 5, 2019
 */

#include <iostream>

#define V(x) std::cout << x << std::endl

#include "matrix.h"

int main() {
    V("- BEGIN -");

    math4610::matrix<double> mat(
        3, 4,
        {
            5, -6, -7,   7, 
            3, -2,  5, -17, 
            2,  4, -3,  29
        }
    );

    auto a = mat.rref();
    V("");
    a.print();
    V("");

    V("- END OF LINE -");
    return 0;
}
