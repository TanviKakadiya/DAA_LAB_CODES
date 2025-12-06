#include <bits/stdc++.h>
using namespace std;
int knapsackGreedy(vector<int> &wt, vector<int> &val, int cap)
{
    int n = wt.size();
    vector<pair<double, int>> ratio;
    for (int i = 0; i < n; i++)
        ratio.push_back({(double)val[i] / wt[i], i});
    sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());

    int totalval = 0;

    for (auto &r : ratio)
    {
        int idx = r.second;
        if (wt[idx] <= cap)
        {
            totalval += val[idx];
            cap -= wt[idx];
        }
    }

    return totalval;
}

int main()
{
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int cap = 50;

    cout << "Greedy Result: "
         << knapsackGreedy(wt, val, cap) << endl;

    return 0;
}