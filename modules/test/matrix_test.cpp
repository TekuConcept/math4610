/**
 * Created by TekuConcept on November 5, 2019
 */

#include <iostream>

#define V(x) std::cout << x << std::endl

#include "matrix.h"
#include "vector_ops.h"

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


void
examples()
{
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

    math4610::matrix<double> mat3{
        4, 4,
        {
            1, 2, 3, 4,
            2, 5, 6, 7,
            3, 6, 8, 9,
            4, 7, 9, 1
        }
    };
    V("Symmetric: " << mat3.is_symmetric());
}


void
jacobi_seidel_test()
{
    size_t n = 3;
    double lower = -10.0;
    double upper =  10.0;

    std::vector<double> ones(n, 1);
    std::vector<math4610::matrix<double>> tests{
        math4610::matrix<double>::create_random(n, lower, upper, false, false),
        math4610::matrix<double>::create_random(n, lower, upper, false, true),
        math4610::matrix<double>::create_random(n, lower, upper, true, false),
        math4610::matrix<double>::create_random(n, lower, upper, true, true)
    };
    std::vector<std::vector<double>> tests_b;
    for (auto& mat : tests)
        tests_b.push_back(mat * ones);
    
    for (size_t i = 0; i < tests.size(); i++) {
        auto jacobi = tests[i].jacobi_solver(tests_b[i]);
        auto seidel = tests[i].seidel_solver(tests_b[i]);
        V(i << ":");
        tests[i].print();
        V("b: " << tests_b[i]);
        V("j: " << jacobi);
        V("s: " << seidel);
        V("");
    }
}


int main() {
    V("- BEGIN -");

    jacobi_seidel_test();

    V("- END OF LINE -");
    return 0;
}
