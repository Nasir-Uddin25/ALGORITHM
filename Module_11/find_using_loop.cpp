#include <bits/stdc++.h>
using namespace std;
int leader[1005];

int find(int val)
{
    while (leader[val] != -1)
    {
        cout << val << endl;
        val = leader[val];
    }

    return val;
}
int main()
{
    memset(leader, -1, sizeof(leader));
    leader[0] = 1;
    leader[1] = -1;
    leader[2] = 1;
    leader[3] = 1;
    leader[4] = 5;
    leader[5] = 3;

    // for (int i = 0; i < 6; i++)
    //     cout << leader[i] << " ";
    cout << find(4) << endl;
    return 0;
}