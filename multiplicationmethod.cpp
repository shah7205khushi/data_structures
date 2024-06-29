#include <iostream>
#include <cmath> 
using namespace std;

int multiplicationHash(int key, int ts, double A) {
    double fracPart = key * A - floor(key * A);
    return floor(ts * fracPart);
}

int main() {

    const double A = (sqrt(5) - 1) / 2;

    // Table size
    const int ts = 100;

    cout << "Multiplication hash for 1234 with table size 100: " << multiplicationHash(1234, ts, A) << endl;
    cout << "Multiplication hash for 4565 with table size 100: " << multiplicationHash(4565, ts, A) << endl;
    cout << "Multiplication hash for 987654321 with table size 100: " << multiplicationHash(987654321, ts, A) << endl;
    cout << "Multiplication hash for 111222333444 with table size 100: " << multiplicationHash(111222333444, ts, A) << endl;
    return 0;
}

