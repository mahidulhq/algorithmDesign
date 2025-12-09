#include <iostream>
using namespace std;


unsigned long long factorial(int n) {

    if (n == 0 || n == 1) {
        return 1;
    }
    else {

        return n * factorial(n - 1);
    }
}

int main() {
    int n;

    cout << "Enter a integer: " << endl;
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        unsigned long long result = factorial(n);
        cout << n << "! = " << result << endl;
    }

    return 0;
}
