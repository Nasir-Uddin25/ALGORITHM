#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[1005];
int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> edge_list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;

    int src, dst;
    cin >> src;

    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }

 

    bool cycle = false;
    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;

        if (dis[a] + c < dis[b])
            cycle = true;
    }

    if (cycle)
        cout << "Negative Cycle Detected" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            cout << i << "->" << dis[i] << endl;
    }

    return 0;
}