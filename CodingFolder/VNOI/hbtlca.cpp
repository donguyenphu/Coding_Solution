#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+3;
ll n,q;
ll root=0;
vector <ll> adj[N];
ll rt,u,v;
string sk;
ll pa[N][40],height[N];
void dfs(ll u,ll pre) {
    for (auto it : adj[u]) {
        if (it==pre) continue;
        else {
            pa[it][0]=u;
            height[it]=height[u]+1;
            dfs(it,u);
        }
    }
}
void pre(ll lgg) {
    for (ll i=1;i<=lgg;i++) {
        for (ll j=1;j<=n;j++) {
            pa[j][i]=pa[pa[j][i-1]][i-1];
        }
    }
}
ll lca(ll u,ll v) {
    if (u==v) return u;
    if (height[u] < height[v]) swap(u,v);
    ll dif=abs(height[u]-height[v]);
    if (dif >=1) {
        ll val=__lg(dif);
        for (ll j=0;j<=val;j++) {
            if ((dif>>j)&1) {
                u=pa[u][j];
            }
        }
    }
    if (u==v) return v;
    for (ll j=22;j>=0;j--) {
        if (pa[u][j] != pa[v][j]) {
            u=pa[u][j];
            v=pa[v][j];
        }
    }
    return pa[u][0];
}
ll lpv(ll u,ll v,ll root) {
  ///  cout<<u<<' '<<v<<' '<<root<<endl;
    ll tm1=u,tm2=v,tm3=root;
    ll uv=lca(tm1,tm2);
    ll ur=lca(tm1,tm3);
    ll vr=lca(tm2,tm3);
   /** if (root==6) {
        cout<<uv<<' '<<ur<<' '<<vr<<endl;
    } */
    if (ur==vr) return uv;
    else {
        if (uv==ur) return vr;
        else if (uv==vr) return ur;
        else return uv;
    }
    return root;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        cin>>n;
        if (!n) {
            return 0;
        }
        for (ll i=1;i<=n-1;i++) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,-1);
      /**  for (ll i=1;i<=n;i++) {
            cout<<height[i]<<' ';
        } */
       /// cout<<endl;
        pre(__lg(n));
        cin>>q;
        for (ll i=1;i<=q;i++) {
            cin>>sk;
            if (sk=="!") {
                cin>>root;
            }
            else {
                cin>>u>>v;
                cout<<lpv(u,v,root)<<endl;
            }
        }
        root=1;
        for (ll i=1;i<=n;i++) {
            adj[i].clear();
            height[i]=0;
        }
        for (ll i=1;i<=n;i++) {
            for (ll j=0;j<=__lg(n);j++) {
                pa[i][j]=0;
            }
        }
    }
    return 0;
}
