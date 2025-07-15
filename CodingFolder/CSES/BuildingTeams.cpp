#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define pll pair<ll,ll>
#define f freopen
using namespace std;
const ll N=1e5+4;
vector <ll> adj[N];
ll n,m,a,b;
map <ll,ll> mp;
ll visited[N];
bool visited2[N];
ll parent[N];
void dfs(ll u) {
    for (auto v: adj[u]) {
        if (!visited[v]) {
            if (visited[u]==1) {
                visited[v]=2;
            }
            else visited[v]=1;
            dfs(v);
        }
        else {
            if (visited[u]==visited[v]) {
                cout<<"IMPOSSIBLE"<<endl;
                exit(0);
            }
        }
    }
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
            visited[i]=1;
            dfs(i);
        }
    }
    for (ll i=1;i<=n;i++) cout<<visited[i]<<" ";

    return 0;
}

