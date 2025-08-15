#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 3e5 + 2;
vector <int> adj[N];
int n, u, v, q, a, b, c;
int height[N];
int pa[N][30];
int lca(int a, int b) {
    if (height[a] < height[b]) swap(a, b);
    if (a == b) return a;
    int dif = abs(height[a] - height[b]);
    for (int i = 0; i <= __lg(dif); i++) {
        if ((dif>>i) & 1) {
            a = pa[a][i];
        }
    }
    if (a == b) return a;
    for (int i = __lg(height[a]); i >= 0; i--) {
        if (pa[a][i] != pa[b][i]) {
            a = pa[a][i];
            b = pa[b][i];
        }
    }
    return pa[a][0];
}
int dis(int a, int b) {
    return height[a] + height[b] - 2 * height[lca(a,b)];
}
int mov(int ver, int dist) {
    for (int i = 0; i <= __lg(dist); i++) {
        if ((dist>>i)&1) {
            ver = pa[ver][i];
        }
    }
    return ver;
}
void dfs(int u, int pre) {
    for (auto it : adj[u]) {
        if (it == pre) continue;
        else {
            height[it] = height[u] + 1;
            pa[it][0] = u;
            dfs(it, u);
        }
    }
}
void pre() {
    for (int j = 1; j <= __lg(n); j++) {
        for (int i = 1; i <= n; i++) {
            pa[i][j] = pa[pa[i][j-1]][j-1];
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n-1; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    pre();
    cin>>q;
    for (int i = 1; i <= q; i++) {
        cin>>a>>b>>c;
        if (dis(a, b) <= c) {
            cout<<b<<endl;
        }
        else if (dis(a, b) > c) {
            if (lca(a, b) == a) {
                cout<<mov(b, dis(a, b) - c)<<endl;
            }
            else if (lca(a, b) == b) {
                cout<<mov(a, c)<<endl;
            }
            else {
                int res = -1;
                int fdist = dis(a, lca(a,b));
                if (fdist == c) {
                    res = lca(a,b);
                }
                else if (fdist > c) {
                    res = mov(a, c);
                }
                else if (fdist < c) {
                    int rem = c - fdist;
                    res = mov(b, dis(b, lca(a, b)) - rem);
                }
                cout<<res<<endl;
            }
        }
    }
    return 0;
}
