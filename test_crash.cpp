#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr;
    cout << "About to segfault..." << endl;
    *ptr = 100;  // Force segfault
    return 0;
}
