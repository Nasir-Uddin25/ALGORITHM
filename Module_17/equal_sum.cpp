#include <bits/stdc++.h>
using namespace std;
int val[1005];
int dp[1005][1005];

bool subset_sum(int i, int sum) // 0(N * S)
{
    if (i < 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];
    if (val[i] <= sum)
    {
        // 1. bag a rakhbo
        bool opt1 = subset_sum(i - 1, sum - val[i]);
        // 2. bag a rakhbo na
        bool opt2 = subset_sum(i - 1, sum);
        dp[i][sum] = opt1 || opt2;
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

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
        sum += val[i];
    }

    if (sum % 2 == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= sum; j++)
                dp[i][j] = -1;

        if (subset_sum(n - 1, sum / 2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}