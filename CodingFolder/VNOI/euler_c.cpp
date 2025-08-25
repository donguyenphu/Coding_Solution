#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
const long long lim = 2e17;
int n, q, t, s, x, tim = 0;
long long st[4*N], laz[4*N], height[N];
int u, v, w, child[N], lab[N], bac[N];
int pa[N][23], deg[N], a[N], path[N][2];
vector <pair<long long, long long>> adj[N];
void dfs(long long u, long long pre) {
    lab[u] = ++tim;
    bac[lab[u]] = u;
    for (auto it : adj[u]) {
        if (it.first == pre) continue;
        else {
            height[it.first] = height[u] + it.second;
            a[it.first] = it.second;
            deg[it.first] = deg[u] + 1;
            pa[it.first][0] = u;
            child[u]++;
            dfs(it.first, u);
            child[u] += child[it.first];
        }
    }
}
void push(long long id) {
    st[2*id] += laz[id];
    st[2*id+1] += laz[id];
    laz[2*id] += laz[id];
    laz[2*id+1] += laz[id];
    laz[id] = 0;
    return ;
}
void build(long long id, long long l, long long r) {
    if (l == r) {
        st[id] = height[bac[l]];
        return ;
    }
    long long mid = (l + r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id] = max(st[2*id], st[2*id + 1]);
}
void up(long long id, long long l, long long r, long long u, long long v, long long val) {
    if (v < l || r < u) return;
    if (u <= l && v >= r) {
        st[id] += val;
        laz[id] += val;
        return ;
    }
    push(id);
    long long mid = (l+r)>>1;
    up(2*id,l,mid,u,v,val);
    up(2*id+1,mid+1,r,u,v,val);
    st[id] = max(st[2*id], st[2*id+1]);
}
long long get(long long id, long long l, long long r, long long u, long long v) {
    if (v < l || u > r) return -lim;
    if (u <= l && r <= v) return st[id];
    push(id);
    long long mid = (l + r)>>1;
    return max(get(2*id,l,mid,u,v), get(2*id+1,mid+1,r,u,v));
}
int lca(long long a, long long b) {
    if (a == b) return a;
    if (deg[a] < deg[b]) swap(a,b);
    long long dif = abs(deg[a] - deg[b]);
    for (long long i = 0 ;i <= __lg(dif); i++) {
        if ((dif>>i)&1) {
            a = pa[a][i];
        }
    }
    if (a == b) return a;
    for (long long i = __lg(deg[a]); i >= 0; i--) {
        if (pa[a][i] != pa[b][i]) {
            a = pa[a][i];
            b = pa[b][i];
        }
    }
    return pa[a][0];
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n - 1; i++) {
        cin>>u>>v>>w;
        path[i][0] = u;
        path[i][1] = v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1, -1);
    build(1,1,n);
    for (int i = 1 ; i <= __lg(n); i++) {
        for (int j = 1; j <= n; j++) {
            pa[j][i] =  pa[pa[j][i-1]][i-1];
        }
    }
    cin>>q;
    for (int i = 1; i <= q; i++) {
        cin>>t>>s;
        if (t == 1) {
            cin>>x;
            int change = -1;
            if (deg[path[s][0]] > deg[path[s][1]]) change = path[s][0];
            else if (deg[path[s][0]] <= deg[path[s][1]]) change = path[s][1];
            long long dif = x - a[change];
            up(1,1,n,lab[change],lab[change] + child[change], dif);
            a[change] = x;
        }
        else if (t==2) {
            cin>>x;
            int common = lca(s, x);
            cout<<get(1,1,n,lab[s],lab[s]) + get(1,1,n,lab[x],lab[x]) - 2*get(1,1,n,lab[common],lab[common])<<endl;
        }
    }
    return 0;
}
