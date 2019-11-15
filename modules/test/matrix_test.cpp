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


void
solvers_1()
{
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
}


int main() {
    V("- BEGIN -");

    math4610::matrix<double> mat{
        3, 3,
        {
              4,  12, -16,
             12,  37, -43,
            -16, -43,  98
        }
    };
    auto L = mat.cholesky_decompose();
    L.print();

    math4610::matrix<double> mat2{
        4, 4,
        {
            10, -1,  2,  0,
            -1, 11, -1,  3,
             2, -1, 10, -1,
             0,  3, -1,  8
        }
    };
    std::vector<double> b{ 6, 25, 11, 15 };
    auto x = mat2.jacobi_solver(b);
    V(x);


    // solvers_1();

    // math4610::matrix<double> mat{
    //     4, 4,
    //     {
    //         1, 2, 3, 4,
    //         2, 5, 6, 7,
    //         3, 6, 8, 9,
    //         4, 7, 9, 1
    //     }
    // };
    // V("Symmetric: " << mat.is_symmetric());

    V("- END OF LINE -");
    return 0;
}
