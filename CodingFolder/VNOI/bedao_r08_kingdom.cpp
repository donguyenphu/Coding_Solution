#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e6+3;
ll n,u,v,c[N];
vector <ll> cmress={-inf};
ll cnt=0;
vector <pll> st;
vector <ll> kq;
vector <ll> adj[N];
ll al=0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p2.inp","r")) {
        freopen("p2.inp","r",stdin);
        freopen("p2.out","w",stdout);
    }
    cin>>n;
    for (ll i=1;i<=n-1;i++) {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        st.pb({u,v});
    }
    for (ll i=1;i<=n;i++) {
        cin>>c[i];
        cmress.pb(c[i]);
    }
    sort(cmress.begin(),cmress.end());
    cmress.resize(unique(cmress.begin(),cmress.end())-cmress.begin());
    for (ll i=1;i<=n;i++) {
        c[i]=lower_bound(cmress.begin(),cmress.end(),c[i])-cmress.begin();
    }
    for(auto it : st) {
        if (c[it.fi] != c[it.se]) al++;
    }
    for (ll i=1;i<=n;i++) {
        ll sm=0;
        for (auto it : adj[i]) {
            if (c[it] != c[i]) {
                sm++;
            }
        }
        if (sm==al) {
            cnt++;
            kq.pb(i);
        }
    }
    cout<<(!cnt ? "NO" : "YES")<<endl;
    if (cnt) {
        for (auto it : kq) {
            cout<<it<<' ';
        }
    }
    return 0;
}
