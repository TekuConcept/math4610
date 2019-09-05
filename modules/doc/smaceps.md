# Single-Precision Machine Epsilon

**Routine Name:** single_machine_epsilon

**Author:** TekuConcept

**Language:** C/C++

**Description/Purpose:** This routine will compute the single precision value for the machine epsilon, or the number of digits
in the representation of real numbers in single precision. This is a routine for analyzing the behavior of any computer. This
usually will only need to be run one time for each computer.

**Input:** Pointers to store the epsilon error and the final exponent after analyzing. These values can be NULL.

**Output:** There are no return values. All results are saved to the provided non-NULL pointers.

**Usage/Example:**

The routine has two arguments needed to return the values of the precision in terms of the smallest number that can be represented.

    float epsilon;
    int exponent;

    math4610::single_machine_epsilon(&epsilon, &exponent);

    auto power_of_two = 1.0F / std::pow(2.0F, (exponent + 1));

The exponent is the number of binary digits that define the machine epsilon, and the epsilon is related to the decimal version of the same value.

**Implementation/Code:** ( [smaceps.cpp](https://github.com/TekuConcept/math4610/blob/master/modules/source/smaceps.cpp) )

    void
    single_machine_epsilon(
        float* __epsilon,
        int*   __exponent)
    {
        auto one           = 1.0F;
        auto epsilon       = 1.0F;
        auto epsilon_error = 1.0F;
        auto exponent      = -1;

        for (auto i = 0; i < 1000; i++) {
            auto next  = one + epsilon;
            auto error = absolute_error(next, one);
            if (error == 0.0F) break;
            epsilon_error = error;
            epsilon *= 0.5F;
            exponent++;
        }

        if (__epsilon)  *__epsilon  = epsilon_error;
        if (__exponent) *__exponent = exponent;
    }

**Last Modified:** September/2019