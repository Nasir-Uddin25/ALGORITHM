#include <bits/stdc++.h>
using namespace std;
int val[1005];
bool subset_sum(int i, int sum)
{
    if (i < 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (val[i] <= sum)
    {
        // 1. bag a rakhbo
        bool opt1 = subset_sum(i - 1, sum - val[i]);
        // 2. bag a rakhbo na
        bool opt2 = subset_sum(i - 1, sum);
        return opt1 || opt2;
    }
    else
        // 2. bag a rakhbo na
        return subset_sum(i - 1, sum);
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> val[i];
    int sum;
    cin >> sum;

    if (subset_sum(n - 1, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}