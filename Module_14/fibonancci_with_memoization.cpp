#include <bits/stdc++.h>
using namespace std;
int dp[1005];
int fibo(int n)         //0(N)
{
    if (n < 2)
        return n;
    dp[n] =  fibo(n - 1) + fibo(n - 2);
    return dp[n];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
  
    cout << fibo(n);
    return 0;
}