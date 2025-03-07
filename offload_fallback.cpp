#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int N = 10;
    int A[N], B[N], C[N];

    // Initialize input arrays
    for(int i = 0; i < N; i++) {
        A[i] = i;
        B[i] = 2 * i;
    }

    // Offload the parallel region (vector addition) to the target device
    // "map(to: A,B) map(from: C)" means A and B get copied to the device,
    // C is copied back from the device to the host after the offloaded block.
    #pragma omp target map(to: A, B) map(from: C)
    {
        // Distribute the loop iterations across threads on the device
        #pragma omp parallel for
        for (int i = 0; i < N; i++) {
            C[i] = A[i] + B[i];
        }
    }

    // Print the results on the host
    cout << "Result of A[i] + B[i] on the device:" << endl;
    for(int i = 0; i < N; i++) {
        cout << "C[" << i << "] = " << C[i] << endl;
    }

    return 0;
}
