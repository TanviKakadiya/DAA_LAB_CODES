#include <bits/stdc++.h>
using namespace std;

double exponential(double base, int power)
{
    double res = 1;
    if (power >= 0)
    {
        for (int i = 0; i < power; i++)
            res *= base;
    }
    else
    {
        for (int i = 0; i < -power; i++)
            res *= base;
        res = 1 / res;
    }
    return res;
}

int main()
{
    double base;
    int power;

    cout << "Enter number: ";
    cin >> base;
    cout << "Enter exponent: ";
    cin >> power;

    cout << exponential(base, power) << endl;
    return 0;
}