#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n, m;


bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}


int dfs(int si, int sj) {
    vis[si][sj] = true;
    int size = 1; 

    for (int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.') {
            size += dfs(ci, cj); 
        }
    }
    return size;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    memset(vis, false, sizeof(vis));
    int minArea = INT_MAX;
    bool hasComponent = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                hasComponent = true;
                int area = dfs(i, j);
                minArea = min(minArea, area);
            }
        }
    }

    cout << (hasComponent ? minArea : -1) << endl; 
    return 0;
}
