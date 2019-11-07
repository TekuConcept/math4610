/**
 * Created by TekuConcept on November 5, 2019
 */

#include <iostream>

#define V(x) std::cout << x << std::endl

#include "matrix.h"

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

    math4610::matrix<double> mat2(
        3, 3,
        {
            5, -6, -7,
            3, -2,  5,
            2,  4, -3
        }
    );
    std::vector<double> b{ 7, -17, 29 };

    auto a = mat.rref();
    V("");
    a.print();
    V("");

    auto x = mat2.lu_solver(b);
    V(x);

    V("- END OF LINE -");
    return 0;
}
