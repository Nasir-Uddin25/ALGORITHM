// Disjoint Set Union (Union - find) Algorithm
#include <bits/stdc++.h>
using namespace std;
int par[100005];
int group_size[100005];
int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

int components, mx_group_size;
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);

    if (leaderA == leaderB)
        return;
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
        mx_group_size = max(mx_group_size, group_size[leaderA]);
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
        mx_group_size = max(mx_group_size, group_size[leaderB]);
    }
    components--;
}
int main()
{
    int n, e;
    cin >> n >> e;

    components = n;
    mx_group_size = 1;

    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union_by_size(a, b);
        cout << components << " " << mx_group_size << endl;
    }

    return 0;
}