#include <iostream>
#include <omp.h>

int main() {
    int sum_atomic = 0, sum_critical = 0;

    #pragma omp parallel for
    for (int i = 0; i < 1000; ++i) {
        #pragma omp atomic
        sum_atomic += 1;  // Only the addition is protected

        #pragma omp critical
        { sum_critical += 1; }  // Entire block is protected
    }

    std::cout << "Sum using atomic: " << sum_atomic << "\n";
    std::cout << "Sum using critical: " << sum_critical << "\n";

    return 0;
}
    