#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    // 1. A simple parallel region
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        cout << "Hello from thread " << thread_id 
             << " out of " << num_threads << " threads!" << endl;
    }

    // 2. Parallelize a loop to compute a sum
    const int N = 100;
    int arr[N];
    // Initialize array
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;  // [1, 2, 3, ..., 100]
    }

    long long sum = 0; // We'll store the sum of all elements here

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    cout << "Sum of array elements = " << sum << endl;

    return 0;
}

//What you are seeing is normal behavior for parallel output. When multiple threads write to cout at the same time, their messages can interleave in unpredictable ways. That is why you see strings merging into each other rather than printing neatly on separate lines.

//Why Does This Happen?
//Each thread is writing to the standard output buffer concurrently.
//Even though you used endl (which does flush the stream), OpenMP doesn’t guarantee that each thread will atomically print its entire line.
//Consequently, the strings from different threads can get mixed or partially overwritten.