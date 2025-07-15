#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define pll pair<ll,ll>
using namespace std;

ll n,m,a,b,start,en;
const ll N=1e5+3;
vector <ll> adj[N];
vector <ll> res;
bool visited[N];
bool ok=false;
ll cnt=0;
ll parent[N];

bool dfs(ll u) {
    visited[u]=true;
    for (auto it: adj[u]) {
        if (!visited[it]) {
            parent[it]=u;
            if (dfs(it)) {
                return true;
            }
        }
        else if (it != parent[u]) {
            start=it;
            en=u;
            return true;
        }
    }
    return false;
}

void display() {
    ll fi=start;
    res.pb(start);
    while (en != start) {
        res.pb(en);
        en=parent[en];
    }
    res.pb(fi);
    cout<<res.size()<<endl;
    for (auto it: res) cout<<it<<" ";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(visited,false,sizeof(visited));
    cin>>n>>m;
    for (ll i=1;i<=m;i++) {
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (ll i=1;i<=n;i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                display();
                exit(0);
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
