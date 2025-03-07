#include <bits/stdc++.h>
using namespace std;

void print_number(int n)
{

    if (n == 1)
        return ;

    cout << n << endl;
   
    print_number(n++);
}

int main()
{
    int n;
    cin >> n;
    print_number(n);
    return 0;
}