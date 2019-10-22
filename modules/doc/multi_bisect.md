# Multi-Bisection Method

**Routine Name:** multi_bisection

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the closely-approximated roots of the input function, `f(x)`, using the closed-loop bisection method. Between a provided interval and optional number of slices, the algorithm will try to locate as many roots as possible. If the slice interval is too large, some roots may be neglected, but if the slice interval is too small, the algorithm may require more time to search.

**Input:** The function, f(x), the search interval, an optional number of slices to search in, an optional non-zero target value for which to find the root, and an optional minimum error epsilon.

**Output:** The computed roots. An empty set will be returned if no roots were found or an error occured.

**Usage/Example:**

Consider the function `f(x) = sin(PI * x^2 + 3.7)`, code can be written to find its root:

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
    // assuming std::ostream operator is overloaded for std::vector
    VERBOSE("Roots: " << roots);


**Implementation/Code:** ( [bisect.h](https://github.com/TekuConcept/math4610/blob/master/modules/include/bisect.h) )

    template <typename T>
    std::vector<T>
    multi_bisection(
        std::function<T(T)> __f,
        T                   __begin,
        T                   __end,
        unsigned int        __slices  = 100,
        T                   __target  = (T)0,
        T                   __epsilon = (T)1.0E-5)
    {
        if ((__slices == 0) || (__begin == __end)) return { };
        if (__end < __begin) std::swap(__end, __begin);

        std::vector<T> roots;
        std::vector<std::pair<T,T>> intervals;
        auto delta = (__end - __begin) / __slices;
        auto sign_check = [](T x) -> int {
            if (x >= 0) return 1;
            else if (x < 0) return -1;
        };

        // generate intervals with roots
        auto last_pair  = std::make_pair<T,T>((T)__begin, __f(__begin));
        auto last_check = sign_check(last_pair.second);
        for (auto x = __begin + delta; x <= __end; x += delta) {
            auto next_pair  = std::make_pair<T,T>((T)x, __f(x));
            auto next_check = sign_check(next_pair.second);
            if (next_check != last_check) {
                if (last_pair.second < next_pair.second)
                    intervals.push_back(std::make_pair<T,T>
                    ((T)next_pair.first, (T)last_pair.first));
                else intervals.push_back(std::make_pair<T,T>
                    ((T)last_pair.first, (T)next_pair.first));
            }
            last_pair  = next_pair;
            last_check = next_check;
        }

        // find roots
        for (auto& interval : intervals)
            roots.push_back(bisection<T>(
                __f,
                interval.first,
                interval.second,
                __target,
                __epsilon));

        return roots;
    }

**Last Modified:** October/2019
