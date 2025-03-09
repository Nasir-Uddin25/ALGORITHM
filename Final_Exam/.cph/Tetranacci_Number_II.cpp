#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    if (n == 0 || n == 1 || n == 2 || n == 3)
        return n;

    int tetranacci[n + 1];
    tetranacci[0] = 0;
    tetranacci[1] = 1;
    tetranacci[2] = 1;
    tetranacci[3] = 2;
   
    for (int i = 4; i <= n; i++)
    {
        tetranacci[i] = tetranacci[i - 1] + tetranacci[i - 2] + tetranacci[i - 3] + tetranacci[i - 4];
    }

    cout << tetranacci[n] << endl;

    return 0;
}
