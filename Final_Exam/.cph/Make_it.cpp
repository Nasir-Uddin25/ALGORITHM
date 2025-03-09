#include <bits/stdc++.h>
using namespace std;

int input;

bool fun( int n)
{
    if (n > input)
        return false;

    if (n == input)
        return true;

    bool t1 = fun(n + 3);
    bool t2 = fun(n * 2);

    return t1 || t2;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> input;
        if (fun(1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}