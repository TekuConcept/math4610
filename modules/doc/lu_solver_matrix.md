# LU Solver

**Routine Name:** lu_solver

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will solve a system of equations using LU decomposition. A matrix will be decomposed into its upper and lower components. Then the system will be solved for each component; resulting in a complete solution.

**Input:** The matrix and the target.

**Output:** The solution to the system.

**Usage/Example:**

Code can be written as follows:

    math4610::matrix<double> mat2(
        3, 3,
        {
            5, -6, -7,
            3, -2,  5,
            2,  4, -3
        }
    );
    std::vector<double> b{ 7, -17, 29 };
    auto x = mat.lu_solver(&upper, &lower);

**Implementation/Code:** ( [matrix.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/matrix.h) )
See also [lu_matrix](https://github.com/TekuConcept/math4610/blob/master/modules/doc/lu_matrix.md) and [rref_matrix](https://github.com/TekuConcept/math4610/blob/master/modules/doc/rref_matrix.md).

    std::vector<T> lu_solver(const std::vector<T>& __b) const
    {
        matrix upper, lower;
        lu_decompose(&upper, &lower);
        auto y = lower.rref(__b);
        return upper.rref(y);
    }

**Last Modified:** November/2019
