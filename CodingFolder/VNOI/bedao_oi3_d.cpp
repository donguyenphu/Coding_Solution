#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+3;
ll dis[N][3];
ll ori[N][3];
vector <pll> adj[N];
bool fin[N],mil[N];
ll n,m,k,u,v,w,idx,ck;
struct node {
    ll dis,ver;
    bool mark;
};
struct cmp {
    bool operator()(node a,node b) {
        return a.dis >= b.dis;
    }
};
void dij() {
    priority_queue <node,vector<node>,cmp> pq;
    for (ll i=1;i<=n;i++) {
        dis[i][0]=dis[i][1]=inf;
    }
    for (ll i=1;i<=n;i++) {
        if (mil[i]) {
            dis[i][0]=0;
            ori[i][0]=i;
            pq.push({0,i,0});
            if (!fin[i]) {
                dis[i][1]=0;
                ori[i][1]=i;
            }
        }
    }
    while (pq.size()) {
        ll u=pq.top().ver;
        ll v=pq.top().dis;
        bool state=pq.top().mark;
        pq.pop();
        if (v != dis[u][state]) continue;
        for (auto it : adj[u]) {
            if (mil[it.fi] && !fin[it.fi]) continue;
            else {
                if (mil[it.fi] && fin[it.fi]) {
                    if (dis[it.fi][1] > dis[u][0] + it.se && ori[u][0] != it.fi && ori[u][0]) {
                        dis[it.fi][1]=dis[u][0]+it.se;
                        ori[it.fi][1]=ori[u][0];
                      ///  pq.push({dis[it.fi][1],it.fi,1});
                    }
                    else if (dis[it.fi][1] > dis[u][1] +it.se && ori[u][1] != it.fi && ori[u][1]) {
                        dis[it.fi][1]=dis[u][1]+it.se;
                        ori[it.fi][1]=ori[u][1];
                      ///  pq.push({dis[it.fi][1],it.fi,1});
                    }
                }
                else {
                    if (dis[it.fi][0] > dis[u][0]+it.se) {
                        if (ori[u][0] == ori[it.fi][0]) {
                            dis[it.fi][0]=dis[u][0]+it.se;
                            ori[it.fi][0]=ori[u][0];
                            pq.push({dis[it.fi][0],it.fi,0});
                        }
                        else if (ori[u][0] != ori[it.fi][0]) {
                            dis[it.fi][1]=dis[it.fi][0];
                            ori[it.fi][1]=ori[it.fi][0];
                            dis[it.fi][0]=dis[u][0]+it.se;
                            ori[it.fi][0]=ori[u][0];
                            pq.push({dis[it.fi][0],it.fi,0});
                        }
                    }
                    else if (dis[it.fi][1] > dis[u][0]+it.se && ori[u][0] != ori[it.fi][0]) {
                        dis[it.fi][1]=dis[u][0]+it.se;
                        ori[it.fi][1]=ori[u][0];
                        pq.push({dis[it.fi][1],it.fi,1});
                    }
                    else if (dis[it.fi][1] > dis[u][1]+it.se && ori[u][1] != ori[it.fi][0]) {
                        dis[it.fi][1]=dis[u][1]+it.se;
                        ori[it.fi][1]=ori[u][1];
                        pq.push({dis[it.fi][1],it.fi,1});
                    }
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
    if (fopen("milktea.inp","r")) {
        freopen("milktea.inp","r",stdin);
        freopen("milktea.out","w",stdout);
    }
    cin>>n>>m>>k;
    for (ll i=1;i<=m;i++) {
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    for (ll i=1;i<=k;i++) {
        cin>>idx>>ck;
        mil[idx]=true;
        fin[idx]=(ck ? true : false);
    }
    dij();
    for (ll i=1;i<=n;i++) {
        if (mil[i] && fin[i]) {
            cout<<dis[i][1]<<' ';
        }
        else cout<<dis[i][0]<<' ';
    }
    return 0;
}
