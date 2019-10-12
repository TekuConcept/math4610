/**
 * Created by TekuConcept on September 23, 2019
 * 
 * This program acts like a sandbox for testing ideas
 * out before actually formatting them into a final
 * draft and including them into the library.
 */

#include <cmath>
#include <iostream>
#include <array>
#include <vector>
#include <sstream>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <type_traits>
#include <stdexcept>

#define V(x) std::cout << x << std::endl

// template <typename T>
// struct matrix {
    // const std::vector<std::vector<T>>& u;

    // matrix() : u(m_u) {};
    // matrix(std::initializer_list<std::initializer_list<T>> v) : u(m_u) {
    //     m_u.resize(v.size());
    //     size_t width = 0;
    //     if (v.size() > 0) {
    //         width = v.begin()->size();
    //         if (width == 0) return;
    //     }

    //     auto* y = v.begin();
    //     while (y != v.end()) {
    //         if (y->size() != width)
    //             // todo: enforce this durring compile-time
    //             throw std::runtime_error("non-uniform matrix data");
    //         auto* x = y->begin();
    //         while (x != y->end()) {
    //             V(y << ":" << x << " -> " << *x);
    //             x++;
    //         }
    //         y++;
    //     }
    //     // std::vector<T> c(v.begin(), v.end());
    //     // std::copy_n(c.begin(), U, x.begin());
    // }
// };

// template <typename T, size_t U = 3, size_t V = 1>
// struct matrix {
//     #define mat_begin {{{
//     #define mat_end   }}}

//     std::array<std::array<T, U>, V> data;

//     std::string
//     to_string() const
//     {
//         std::ostringstream os;
//         os << "[";
//         auto first_row = true;
//         for (auto& row : data) {
//             auto first_cell = true;
//             if (!first_row) os << ";";
//             else first_row = false;
//             for (auto& cell : row) {
//                 if (!first_cell) os << ",";
//                 else first_cell = false;
//                 os << cell;
//             }
//         }
//         os << "]";
//         return os.str();
//     }

//     inline T
//     mag() const
//     { return mag(*this); }

//     static T
//     mag(const matrix<T,U,V>& __v)
//     {
//         T sum = (T)0;
//         for (size_t r = 0; r < V; i++)
//             for (size_t c = 0; c < U; c++)
//                 sum += __lm.data[r][c] * __rm.data[r][c];
//         return (T)std::sqrt(sum);
//     }

//     inline T
//     dot(const matrix<T,U,V> __rv) const
//     { return dot(*this, __rv); }

//     static T
//     dot(
//         const matrix<T,U,V>& __lm,
//         const matrix<T,U,V>& __rm)
//     {
//         T sum = (T)0;
//         for (size_t r = 0; r < V; i++)
//             for (size_t c = 0; c < U; c++)
//                 sum += __lm.data[r][c] * __rm.data[r][c];
//         return sum;
//     }

//     inline void operator+=(const matrix<T,U,V>& __rm)
//     { add(*this, __rm); }

//     inline matrix&
//     add(const matrix<T,U,V>& __rm)
//     { add(*this, __rm); return *this; }

//     static void
//     add(
//         matrix<T,U,V>&       __lm,
//         const matrix<T,U,V>& __rm)
//     {
//         for (size_t r = 0; r < V; r++)
//             for (size_t c = 0; c < U; c++)
//                 __lm.data[r][c] += __rm.data[r][c];
//     }

//     inline void operator-=(const matrix<T,U,V>& __rm)
//     { sub(*this, __rm); }

//     inline matrix&
//     sub(const matrix<T,U,V>& __rm)
//     { sub(*this, __rm); return *this; }

//     static void
//     sub(
//         matrix<T,U,V>&       __lm,
//         const matrix<T,U,V>& __rm)
//     {
//         for (size_t r = 0; r < V; r++)
//             for (size_t c = 0; c < U; c++)
//                 __lm.data[r][c] -= __rm.data[r][c];
//     }

//     friend std::ostream&
//     operator<<(
//         std::ostream& os,
//         const matrix<T,U,V>& v)
//     { return os << v.to_string(); }

//     friend matrix<T,U,V>
//     operator+(
//         const matrix<T,U,V>& __lm,
//         const matrix<T,U,V>& __rm)
//     {
//         matrix<T,U,V> result;
//         for (size_t r = 0; r < V; r++)
//             for (size_t c = 0; c < U; c++)
//                 result.data[r][c] = __lm.data[r][c] + __rm.data[r][c];
//         return result;
//     }

//     friend matrix<T,U,V>
//     operator-(
//         const matrix<T,U,V>& __lm,
//         const matrix<T,U,V>& __rm)
//     {
//         matrix<T,U,V> result;
//         for (size_t r = 0; r < V; r++)
//             for (size_t c = 0; c < U; c++)
//                 result.data[r][c] = __lm.data[r][c] - __rm.data[r][c];
//         return result;
//     }
// };

int main() {
    V("-- BEGIN --");

    // typedef matrix<double,3,3> dmat3x3;

    // dmat3x3 mat1
    // mat_begin
    //     { 1, 2, 3 },
    //     { 4, 5, 6 },
    //     { 7, 8, 9 }
    // mat_end;

    // dmat3x3 I
    // mat_begin
    //     { 1, 0, 0 },
    //     { 0, 1, 0 },
    //     { 0, 0, 1 }
    // mat_end;

    // mat1.add(I).sub(I).add(I);
    // mat1 += I;

    // V("matrix: " << mat1);

    // mat1 = I + I - I;

    // V("matrix: " << mat1);

    // matrix<double> v2{ 4, 5, 6 };
    // auto d = v1.dot(v2);
    // V(v1 << " dot " << v2 << " = " << d);

    // matrix<matrix<double>> mat{
    //     { 1, 0, 0 },
    //     { 0, 1, 0 },
    //     { 0, 0, 1 }
    // };
    // V("Matrix: " << mat);

    V("-- END OF LINE --");
    return 0;
}
