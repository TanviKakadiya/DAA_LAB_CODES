#include <bits/stdc++.h>
using namespace std;

void rabinKarp(string text, string pattern, int prime = 101)
{
    int n = text.length();
    int m = pattern.length();
    int base = 256;

    long long patternHash = 0;
    long long textHash = 0;
    long long h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * base) % prime;
    for (int i = 0; i < m; i++)
    {
        patternHash = (patternHash * base + pattern[i]) % prime;
        textHash = (textHash * base + text[i]) % prime;
    }

    cout << "Pattern found at positions: ";
    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == textHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << i << " ";
        }
        if (i < n - m)
        {
            textHash = (base * (textHash - text[i] * h) + text[i + 1 + (m - 1)]) % prime;
            if (textHash < 0)
                textHash += prime;
        }
    }
    cout << endl;
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    rabinKarp(text, pattern);

    return 0;
}