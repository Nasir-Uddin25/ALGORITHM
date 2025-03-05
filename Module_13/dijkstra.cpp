#include <bits/stdc++.h>
using namespace std;

vector<pair<long long int, long long int>> adj_list[100005];
long long int dis[100005];
long long int parent[100005];

void dijkstra(long long int src)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<long long int, long long int> par = pq.top();
        pq.pop();
        long long int par_node = par.second;
        long long int par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            long long int child_node = child.first;
            long long int child_dis = child.second;
            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node], child_node});
                parent[child_node] = par_node;
            }
        }
    }
}
int main()
{
    long long int n, e;
    cin >> n >> e;
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    
    for (long long int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
        parent[i] = -1;
    }
    dijkstra(1);
    if (dis[n] == LLONG_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        long long int node = n;
        vector<long long int> path;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}