#include <iostream>
using namespace std;


int fibonacci(int n)
{

    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {

        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;

    cout << "Enter the position (n) to find Fibonacci number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Please enter a non-negative number." << endl;
    }
    else
    {
        int result = fibonacci(n);
        cout << "Fibonacci number at position " << n << " is: " << result << endl;
    }

    // Display first 10 Fibonacci numbers
    cout << "First 10 Fibonacci numbers: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << fibonacci(i) << " " << endl;
    }

    return 0;
}
