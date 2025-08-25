#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 2;
const long long lim = 2e17;
long long n, q, a[N], t, s, x, st[N*4], tim = 0;
long long u, v, height[N], child[N], lab[N], bac[N], laz[4*N];
vector <long long> adj[N];
void dfs(long long u, long long pre) {
    lab[u] = ++tim;
    bac[lab[u]] = u;
    for (auto it : adj[u]) {
        if (it == pre) continue;
        else {
            height[it] = height[u] + a[it];
            child[u]++;
            dfs(it, u);
            child[u] += child[it];
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
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for (long long i = 1; i <= n; i++)  {
        cin>>a[i];
    }
    for (long long i = 1; i <= n - 1; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    height[1] = a[1];
    dfs(1, -1);
    build(1,1,n);
    for (long long i = 1; i <= q; i++) {
        cin>>t>>s;
        if (t == 1) {
            cin>>x;
            long long dif = x - a[s];
            up(1,1,n,lab[s],lab[s] + child[s], dif);
            a[s] = x;
        }
        else {
            cout<<get(1,1,n,lab[s],lab[s])<<endl;
        }
    }
    return 0;
}
