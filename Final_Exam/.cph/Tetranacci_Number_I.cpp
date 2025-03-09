#include <bits/stdc++.h>
using namespace std;
int dp[35];
int tetranacci(int n)
{
    // base case
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    // recursive call
    dp[n] = tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
    return dp[n];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;

    cout << tetranacci(n) << endl;
    return 0;
}