/**
 * Created by TekuConcept on October 30, 2019
 */

#include <iostream>
#include <sstream>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        std::ostringstream os;
        os << "hello parallel world from thread #"
            << thread_id << "\n";
        std::cout << os.str() << std::flush;
    }
    return 0;
}
