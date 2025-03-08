#include <bits/stdc++.h>
using namespace std;
int price[1005], weight[1005];
int dp[1005][1005];

int knapsack(int i, int mx_weight)
{
    // base case
    if (i < 0 || mx_weight <= 0)
        return 0;

    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];

    if (weight[i] <= mx_weight)
    {
        // 2 options
        // 1. bag a rakhbo.   2. bag a rakhbo na
        int opt1 = knapsack(i - 1, mx_weight - weight[i]) + price[i];
        int opt2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(opt1, opt2);
        return dp[i][mx_weight];
    }
    else
    {
        // 1 option
        //  2. bag a rakhbo na
        dp[i][mx_weight] = knapsack(i - 1, mx_weight);
        return dp[i][mx_weight];
    }
}
int main()
{
    int n, mx_weight; // 4

        cin >> n;

    for (int i = 0; i < n; i++) // 10 4 7 5
        cin >> price[i];
    for (int i = 0; i < n; i++) // 4 3 2 5
        cin >> weight[i];

    cin >> mx_weight; // 8

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= mx_weight; j++)
            dp[i][j] = -1;

    cout << knapsack(n - 1, mx_weight); // last index number, bag er weight
    return 0;
}