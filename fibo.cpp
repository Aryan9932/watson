#include <iostream>
using namespace std;

// Recursive Fibonacci
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1)
         + fibonacciRecursive(n - 2);
}

// Non-recursive Fibonacci
void fibonacciIterative(int n) {
    int a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        cout << a << " ";

        int c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    if (n < 0) {
        cout << "Enter a non-negative number.";
        return 0;
    }

    cout << "\nRecursive Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }

    cout << "\nIterative Fibonacci: ";
    fibonacciIterative(n);

    return 0;
}