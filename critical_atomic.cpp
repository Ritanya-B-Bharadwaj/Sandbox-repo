#include <iostream>
#include <omp.h>
#include <climits>

int main() {
    int max_value = INT_MIN;
    int arr[1000];

    
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }

    #pragma omp parallel for
    for (int i = 0; i < 1000; i++) {
        #pragma omp critical
        {
            if (arr[i] > max_value) {
                max_value = arr[i];
            }
        }
    }

    std::cout << "Correct Max Value (Using Critical): " << max_value << std::endl;
    return 0;
}
