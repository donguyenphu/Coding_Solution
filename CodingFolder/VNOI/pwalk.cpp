#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e3+4;
vector <pll> adj[N];
ll pa[N][32],dis[N];
ll height[N];
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
    /// v > u
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
ll n,u,v,w,q,l[N],r[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    /// 1
    cin>>n>>q;
    for (ll i=1;i<=n-1;i++) {
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs(1,-1);
    for (ll j=1;j<=__lg(n);j++) {
        for (ll i=1;i<=n;i++) {
            pa[i][j]=pa[pa[i][j-1]][j-1];
        }
    }
    for (ll i=1;i<=q;i++) {
        cin>>l[i]>>r[i];
        cout<<dis[l[i]]+dis[r[i]]-2*dis[lca(l[i],r[i])]<<endl;
    }
    return 0;
}
s
