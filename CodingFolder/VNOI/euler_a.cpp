#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long N = 2e5 + 3;
long long st[N*4];
long long a[N];
long long n, q, t, s, x, u, v;
vector <long long> adj[N];
long long child[N], lab[N], bac[N];
long long tim = 0;
void dfs(long long u, long long pre) {
    lab[u] = ++tim;
    bac[lab[u]] = u;
    for (auto it : adj[u]) {
        if (it == pre) continue;
        else {
            child[u]++;
            dfs(it, u);
            child[u] += child[it];
        }
    }
}
void build(long long id, long long l , long long r) {
    if (l==r) {
        st[id] = a[bac[l]];
        return ;
    }
    long long mid = (l + r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id] = st[2*id] + st[2*id+1];
}
void up(long long id, long long l, long long r, long long idx, long long val) {
    if (idx < l || idx > r) return ;
    if (l==r) {
        st[id] = val;
        return ;
    }
    long long mid = (l + r)>>1;
    up(2*id,l,mid,idx,val);
    up(2*id+1,mid+1,r,idx,val);
    st[id] = st[2*id] + st[2*id + 1];
}
long long get(long long id, long long l, long long r, long long u, long long v) {
    if (v < l || u > r) return 0LL;
    if (u <= l && r <= v) return st[id];
    long long mid = (l + r)>>1;
    return get(2*id,l,mid,u,v) + get(2*id+1,mid+1,r,u,v);
}
signed  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    cin>>n>>q;
    for (long long i =1 ; i <= n; i++) {
        cin>>a[i];
    }
    for (long long i = 1; i <= n-1; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    build(1,1,n);
    for (long long i = 1; i <= q; i++) {
        cin>>t;
        if (t == 1) {
            cin>>s>>x;
            up(1,1,n,lab[s],x);
        }
        else {
            cin>>s;
            cout<<get(1,1,n,lab[s],lab[s] + child[s])<<endl;
        }
    }
    return 0;
}
