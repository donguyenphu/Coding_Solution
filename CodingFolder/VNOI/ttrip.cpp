#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 2;
const int lim = 1e9;
int n, a[N][N], d[N][N];
vector <pair<int,int>> adj[N];
set <int> s;
long long ss = 0, mi = lim, curPoint = -1;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        if (i > 1 && i < n) s.insert(i);
        for (int j = 1; j <= n; j++) {
            cin>>a[i][j];
            if (a[i][j]) adj[i].push_back({j,a[i][j]});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = lim;
        }
        d[i][i] = 0;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({d[i][i],i});
        while (pq.size()) {
            int u = pq.top().second;
            int v = pq.top().first;
            pq.pop();
            if (v != d[i][u]) continue;
            for (auto it : adj[u]) {
                if (d[i][it.first] > d[i][u] + it.second) {
                    d[i][it.first] = d[i][u] + it.second;
                    pq.push({d[i][it.first], it.first});
                }
            }
        }
    }
    for (int i = 2; i <= n-1; i++) {
        if (d[1][i] < mi) {
            mi = d[1][i];
            curPoint = i;
        }
    }
    s.erase(curPoint);
    ss += mi;
    while (s.size()) {
        long long mi2 = lim, tmp = curPoint;
        for (int i = 2; i <= n-1; i++)  {
            if (i != curPoint && s.find(i) != s.end() && d[curPoint][i] < mi2) {
                mi2 = d[curPoint][i];
                tmp = i;
            }
        }
        s.erase(tmp);
        ss+=mi2;
        curPoint = tmp;
    }
    ss+= d[curPoint][n];
    cout<<ss;
    return 0;
}
