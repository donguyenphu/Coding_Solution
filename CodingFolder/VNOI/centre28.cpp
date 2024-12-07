#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll mod=1e9+7;
const ll inf=2e18;
const ll N=2e5+3;
ll dis[N][5],n,m,u,v,w;
ll tmp[N][5];
set <ll> st;
vector <pll> adj[N];
void dij(ll s,ll tt) {
    for (ll i=0;i<=n;i++) {
        dis[i][tt]=inf;
        tmp[i][tt]=1LL;
    }
    dis[s][tt]=0LL;
    tmp[s][tt]=1LL;
    priority_queue <pll,vector<pll>,greater<pll>> pq;
    pq.push({0LL,s});
    while (!pq.empty()) {
        ll u=pq.top().se,v=pq.top().fi;
        pq.pop();
        if (v > dis[u][tt]) continue;
        for (auto it : adj[u]) {
            if (dis[it.fi][tt] > dis[u][tt]+it.se) {
                dis[it.fi][tt]=dis[u][tt]+it.se;
                tmp[it.fi][tt]=tmp[u][tt];
                pq.push({dis[it.fi][tt],it.fi});
            }
            else if (dis[it.fi][tt] == dis[u][tt]+it.se) {
                if (dis[it.fi][tt] == dis[u][tt]+it.se) {
                    tmp[it.fi][tt]+=tmp[u][tt];
                    dis[it.fi][tt]=dis[u][tt]+it.se;
                }
            }
        }
    }
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
    }
    dij(1,0);
    dij(n,1);
 //   ll ff=n;
    for (ll i=2;i<=n-1;i++) {
        if (dis[i][1]==inf || dis[i][0]==inf) {
            st.insert(i);
        }
        else {
            if (dis[i][0]+dis[i][1] > dis[n][0] || dis[i][0]+dis[i][1]> dis[1][1]) {
                st.insert(i);
            }
            else {
                if (dis[i][0]+dis[i][1]==dis[n][0] || dis[i][0]+dis[i][1]==dis[1][1]) {
                    if (tmp[i][0]*tmp[i][1]==tmp[n][0] || tmp[i][0]*tmp[i][1]==tmp[1][1]) {
                        continue;
                    }
                    else {
                        st.insert(i);
                    }
                }
            }
        }
    }
    cout<<st.size()<<endl;
    for (auto it : st) {
        cout<<it<<endl;
    }
    return 0;
}
