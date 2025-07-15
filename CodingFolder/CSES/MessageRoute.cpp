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
const ll N=1e5+2;
const ll INF=1e17;
vector <pll> adj[N];
vector <ll> res;
ll trace[N];
ll d[N];
void dk(ll i) {
    d[i]=0;
    priority_queue <pll, vector <pll> ,greater <pll>> pq;
    pq.push({0,i});
    while (!pq.empty()) {
        ll u=pq.top().se;
        ll v=pq.top().fi;
        pq.pop();
        if (v != d[u]) continue;
        for (auto it : adj[u]) {
            if (d[u]+it.se< d[it.fi]) {
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
    ll n,m;
    cin>>n>>m;
    for (ll i=1;i<=m;i++) {
        ll a,b;
        cin>>a>>b;
        adj[a].pb({b,1});
        adj[b].pb({a,1});
    }
    for (ll i=0;i<=n;i++) d[i]=INF;
    dk(1);
    if (d[n]==INF) cout<<"IMPOSSIBLE"<<endl;
    else {
        cout<<d[n]+1<<endl;
        ll i=n;
        res.pb(n);
        while (i != 1) {
            res.pb(trace[i]);
            i=trace[i];
        }
        reverse(res.begin(),res.end());
        for (auto it: res) cout<<it<<" ";
    }
}
