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

vector<Edge> edge_list;
long long int dis[1005];
int n, e;
void bellman_ford(int src)
{
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;

    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
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

        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        exit(0);
    }
}

int main()
{

    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;

    bellman_ford(src);

    int t, dst;
    cin >> t;
    while (t--)
    {

        cin >> dst;

        if (dis[dst] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dis[dst] << endl;
    }

    return 0;
}