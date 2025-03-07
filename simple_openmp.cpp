#include <iostream>
#include <omp.h>
#include <unistd.h>  // for usleep
using namespace std;

int main() {
    // ---------------------------------------------------------
    // 2) Parallelize a loop to compute a sum
    // ---------------------------------------------------------
    cout << "\n--- Parallelize a loop to compute a sum ---" << endl;

    const int N = 10;
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;  // Fill with 1..10
    }

    long long sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    cout << "Sum of array elements = " << sum << endl;

    // ---------------------------------------------------------
    // 3) Ordered Output with Critical
    // ---------------------------------------------------------
    cout << "\n--- Ordered Output (Using Critical) ---" << endl;

    #pragma omp parallel
    {
        int thread_id   = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        #pragma omp critical
        {
            cout << "Ordered: Hello from thread " << thread_id
                 << " out of " << num_threads << " threads!" << endl;
        }
    }

    return 0;
}
