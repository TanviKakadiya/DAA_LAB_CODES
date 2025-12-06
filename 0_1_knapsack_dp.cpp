#include <bits/stdc++.h>
using namespace std;

int knapsackDP(vector<int> &wt, vector<int> &value, int cap)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int cap = 1; cap <= cap; cap++)
        {

            if (wt[i - 1] <= cap)
            {
                dp[i][cap] = max(
                    value[i - 1] + dp[i - 1][cap - wt[i - 1]],
                    dp[i - 1][cap]);
            }
            else
            {
                dp[i][cap] = dp[i - 1][cap];
            }
        }
    }

    return dp[n][cap];
}

int main()
{
    vector<int> wt = {10, 20, 30};
    vector<int> value = {60, 100, 120};
    int cap = 50;

    cout << "DP Knapsack Result: "
         << knapsackDP(wt, value, cap) << endl;

    return 0;
}