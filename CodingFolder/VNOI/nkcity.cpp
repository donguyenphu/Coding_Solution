#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+3;
vector <pll> adj[N];
ll n,m,q,u,v,w;
ll l[N],r[N];
ll pa[N][32],dis[N],height[N];
vector <pll> after[N];
void dfs(ll u,ll pre) {
    for (auto it : adj[u]) {
        if (it.first==pre) continue;
        else {
            dis[it.first]=dis[u]+it.second;
            height[it.first]=height[u]+1;
            pa[it.first][0]=u;
            dfs(it.first,u);
        }
    }
}
ll lca(ll u,ll v) {
    if (u==v) return u;
    if (height[u] > height[v]) swap(u,v);
    ll c=v;
    ll val=abs(height[u]-height[v]);
    ll ckk=__lg(abs(height[u]-height[v]));
    for (ll i=0;i<=ckk;i++) {
        if ((val>>i)&1) {
            c=pa[c][i];
        }
    }
    if (c==u) return u;
    for (ll i=__lg(height[u]);i>=0;i--) {
        if (pa[u][i] != pa[c][i]) {
            u=pa[u][i];
            c=pa[c][i];
        }
    }
    return pa[c][0];
}
ll parent[N],siz[N],root=-1;
struct store {
    ll ver1,ver2,weight;
};
vector <store> st;
struct cmp {
    bool operator()(store a,store b) {
        return a.weight > b.weight;
    }
};
void make() {
    for (ll i=1;i<=n;i++) {
        parent[i]=i;
        siz[i]=1;
    }
}
ll fin(ll aa) {
    return (aa==parent[aa] ? aa : fin(parent[aa]));
}
void join(ll u,ll v) {
    u=fin(u),v=fin(v);
    if (u==v) return;
    if (siz[u] < siz[v]) swap(u,v);
    siz[u]+=siz[v];
    parent[v]=u;
    return ;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    cin>>n>>m;
    for (ll i=1;i<=m;i++) {
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        st.push_back({u,v,w});
    }
    for (ll i=1;i<=n;i++) {
        parent[i]=i;
        siz[i]=1;
    }
    sort(st.begin(),st.end(),[](store x,store y) {
         return x.weight < y.weight;
    });
    ll as=0,ma=0;
    for (auto it : st) {
            ll s1=fin(it.ver1);
            ll s2=fin(it.ver2);
            if (s1==s2) {
                continue;
            }
            else {
                join(it.ver1,it.ver2);
                as+=it.weight;
                ma=max(ma,it.weight);
            }
    }
    cout<<ma;
    return 0;
}
