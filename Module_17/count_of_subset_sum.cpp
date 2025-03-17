#include <bits/stdc++.h>
using namespace std;
int val[1005];
int dp[1005][1005];

int subset_sum(int i, int sum) // 0(N * S)
{
    if (i < 0)
    {
        if (sum == 0)
            return 1;
        else
            return 0;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];
    if (val[i] <= sum)
    {
        // 1. bag a rakhbo
        int opt1 = subset_sum(i - 1, sum - val[i]);
        // 2. bag a rakhbo na
        int opt2 = subset_sum(i - 1, sum);
        dp[i][sum] = opt1 +  opt2;
        return dp[i][sum];
    }
    else
    {
        // 2. bag a rakhbo na
        dp[i][sum] = subset_sum(i - 1, sum);
        return dp[i][sum];
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];
    int sum;
    cin >> sum;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = -1;

    cout << subset_sum(n - 1, sum) << endl;
     
    return 0;
}