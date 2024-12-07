#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
/// DSU CÓ THỂ N^2
/// SMALL TO LARGE(VD : SWAP(A,B))
/// CHỈ MẤT NLOGN!!!
const ll N=2e5+3;
ll a[N],pa[N],siz[N];
ll n,q,type,u,v;
map <ll,ll> mp[N];
void make(ll n) {
    for (ll i=1;i<=n;i++) {
        siz[i]=1;
        pa[i]=i;
    }
}
ll fin(ll a) {
    return (pa[a]==a ? a : pa[a]=fin(pa[a]));
}
/// small to large theo tong so dinh
void upd(ll u,ll v) {
    u=fin(u);
    v=fin(v);
    if (u==v) return ;
    if (siz[u] < siz[v]) swap(u,v);
    siz[u]+=siz[v];
    pa[v]=u;
    for (auto it : mp[v]) {
        mp[u][it.fi]+=it.se;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    cin>>n>>q;
    make(n);
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
        mp[i][a[i]]=1;
    }
    for (ll i=1;i<=q;i++) {
        cin>>type>>u>>v;
        if (type==1) {
            upd(u,v);
        }
        else {

            cout<<mp[fin(u)][v]<<endl;
        }
    }
    return 0;
}
