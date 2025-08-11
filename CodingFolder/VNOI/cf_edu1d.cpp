#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
int cc[N][N];
int numcc[N*N];
char a[N][N];
int n, m, k, x, y;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1 , 1};
bool vis[N][N];
int num = 0;
bool in(int xx, int yy) {
    return (xx >= 1 && xx <= n && yy >= 1 && yy <= m);
}
void bfs(int i, int j) {
    queue<pair<int,int>> q;
    q.push({i, j});
    vis[i][j] = true;
    while (q.size()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int uu = u + dx[i];
            int vv = v + dy[i];
            if (a[uu][vv] == '.' && vis[uu][vv]) continue;
            else {
                if (in(uu, vv)) {
                    if (a[uu][vv] == '*') numcc[cc[u][v]]++;
                    else if (a[uu][vv] == '.') {
                        vis[uu][vv] = true;
                        cc[uu][vv] = cc[u][v];
                        q.push({uu,vv});
                    }
                }
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m ; j++) {
            if (!vis[i][j] && a[i][j] == '.') {
                num++;
                cc[i][j] = num;
                bfs(i, j);
            }
            else continue;
        }
    }
    for (int i = 1; i <= k; i++) {
        cin>>x>>y;
        cout<<numcc[cc[x][y]]<<'\n';
    }
    return 0;
}
