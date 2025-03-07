#include <bits/stdc++.h>
using namespace std;

void print_digit(int n)
{
    if (n == 0)
        return;

    int digit = n % 10;
    print_digit(n / 10);
    cout << digit << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if(n == 0)
        cout << '0';
        print_digit(n);
        cout << endl;
    }

    return 0;
}