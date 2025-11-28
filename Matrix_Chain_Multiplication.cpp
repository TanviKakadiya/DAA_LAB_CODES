#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainMultiplication(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int L = 2; L <= n; L++) { // L = chain length
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    
    vector<int> dims(n + 1);
    cout << "Enter dimensions of matrices (p0 p1 ... pn):\n";
    for (int i = 0; i <= n; i++)
        cin >> dims[i];
    
    int minMultiplications = matrixChainMultiplication(dims);
    
    cout << "Minimum number of multiplications required: " << minMultiplications << endl;
    
    return 0;
}
    