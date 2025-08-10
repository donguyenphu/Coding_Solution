#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e3 + 2;
const int lim = 2e9;
const int dx[5] = {-1, 1, 0, 0};
const int dy[5] = {0, 0, -1, 1};
long long n, m, x, y, xx, yy;
char a[N][N];
bool in(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= m);
}
long long d[N][N];
queue <pair<int,int>> q;
bool vis[N][N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>a[i][j];
            d[i][j] = lim;
            if (a[i][j] == 'B') {
                xx = i;
                yy = j;
            }
            if (a[i][j] == 'C') {
                x = i;
                y = j;
            }
        }
    }
    q.push({xx,yy});
    d[1][1] = 0;
    vis[1][1] = true;
    while (q.size()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4; i++) {
            int ux = u + dx[i];
            int vy = v + dy[i];
            if (vis[ux][vy]) continue;
            if (in(ux, vy) && !vis[ux][vy] && d[ux][vy] > d[u][v] + 1 && a[ux][vy] != '*') {
                vis[ux][vy] = true;
                d[ux][vy] = d[u][v] + 1;
                q.push({ux, vy});
            }
        }
    }
    cout<<d[x][y];
    return 0;
}
