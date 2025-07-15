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
const ll N=2e5+4;
const ll INF=1e17;
ll n,m;
ll a,b,w;
ll trace[N];
ll d[N];
vector <pll> adj[N];
void di (ll s) {
    d[s]=0;
    priority_queue <pll,vector<pll>, greater<pll>> pq;
    pq.push({0,s});
    while (!pq.empty()) {
        ll u=pq.top().se;
        ll v=pq.top().fi;
        pq.pop();
        if (v != d[u]) continue;
        for (auto it: adj[u]) {
            if (d[u]+it.se < d[it.fi]) {
                d[it.fi]=d[u]+it.se;
                trace[it.fi]=u;
                pq.push({d[it.fi],it.fi});
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (ll i=0;i<=n;++i) {
        d[i]=INF;
    }
    for (ll i=1;i<=m;++i) {
        cin>>a>>b>>w;
        adj[a].pb({b,w});
    }
    di(1);
    for (ll i=1;i<=n;i++) {
        cout<<d[i]<<" ";
    }
}
