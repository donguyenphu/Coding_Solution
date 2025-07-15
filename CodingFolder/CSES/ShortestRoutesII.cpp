#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll N=5e2+4;
const ll INF=1e17;
vector <pll> adj[N];
ll d[N];
ll dp[N][N];
ll a,b,w;
ll n,m,x,y,q;
ll trace[N];
bool visited[N];
ll maxn=LONG_MIN;
signed main()
{
    ios_base::sync_with_stdio(0);
   cin>>n>>m>>q;
     for (ll i=0;i<=n;i++) {
        for (ll j=0;j<=n;j++) {
            dp[i][j]=INF;
        }
    }
   for (ll i=0;i<=n;i++) {
        d[i]=INF;
        dp[i][i]=0;
   }
   for (ll i=1;i<=m;i++) {
        cin>>a>>b>>w;
        adj[a].pb({b,w});
        dp[a][b]=min(dp[a][b],w);
        dp[b][a]=min(dp[b][a],w);
        adj[b].pb({a,w});
   }
   for (ll k=1;k<=n;k++) {
        for (ll i=1;i<=n;i++) {
            for (ll j=1;j<=n;j++) {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
   }
   for (ll i=1;i<=q;++i) {
        cin>>x>>y;
        if (dp[x][y]==INF) {
            cout<<-1<<endl;
        }
        else cout<<dp[x][y]<<endl;
   }
}
