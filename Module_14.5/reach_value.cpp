#include <bits/stdc++.h>
using namespace std;

bool reach_value(int n)
{
    if (n == 0)
        return false;
    int value = n * 10;
    return reach_value(n * 10);
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        reach_value(n);
        if (reach_value(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}