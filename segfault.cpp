#include <iostream>

using namespace std;

int main() {
    // Instead of nullptr, allocate memory or use a valid object
    int x = 42;
    int* ptr = &x;

    cout << "Pointer value: " << *ptr << endl;  // Now valid
    return 0;
}
