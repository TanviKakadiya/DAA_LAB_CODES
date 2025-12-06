#include <iostream>
#include <cmath>
using namespace std;

long long karatsuba(long long x, long long y) {
    // Base case for small numbers
    if (x < 10 || y < 10)
        return x * y;
    
    // Calculate the size of the numbers
    int n = max(to_string(x).length(), to_string(y).length());
    int m = n / 2;
    
    // Split the digit sequences
    long long high1 = x / pow(10, m);
    long long low1  = x % (long long)pow(10, m);
    long long high2 = y / pow(10, m);
    long long low2  = y % (long long)pow(10, m);
    
    // 3 recursive calls
    long long z0 = karatsuba(low1, low2);
    long long z1 = karatsuba((low1 + high1), (low2 + high2));
    long long z2 = karatsuba(high1, high2);
    
    return (z2 * pow(10, 2 * m)) + ((z1 - z2 - z0) * pow(10, m)) + z0;
}

int main() {
    long long num1, num2;
    cout << "Enter first large integer: ";
    cin >> num1;
    cout << "Enter second large integer: ";
    cin >> num2;
    
    long long result = karatsuba(num1, num2);
    
    cout << "Result of multiplication (Karatsuba): " << result << endl;
    
    return 0;
}
