#include <bits/stdc++.h>
using namespace std;

bool vis[100005];
int parent[100005];
vector<int> adj_list[100005];
int cnt = 0;

void dfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;


    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
            else if (vis[child] && parent[par] != child)
            {
                cnt++;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= n; i++) // Fixed loop (1-based indexing)
    {
        if (!vis[i])
            dfs(i);
    }

    cout << cnt / 2 << endl; // Each cycle is counted twice in an undirected graph

    return 0;
}
