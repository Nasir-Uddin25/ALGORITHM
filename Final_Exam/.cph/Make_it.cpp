#include <bits/stdc++.h>
using namespace std;

long long int dp[100005];
bool fun(long long int start, long long int target)
{
    if (start == target)
        return true;

    if (start > target)
        return false;

    if (dp[start] != -1)
        return dp[start];

    dp[start] = fun(start + 3, target) || fun(start * 2, target);
    return dp[start];
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        long long int n;
        cin >> n;
        if (fun(1, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
