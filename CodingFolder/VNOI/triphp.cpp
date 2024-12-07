#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll N=1e5+3;
const ll inf=1e16;
bool vis[N];
vector <ll> adj[N];
vector <ll> divv[N];
vector <pair<ll,ll>> st;
ll n,u,v,res[N],tim=0,num[N];
ll dis[N],pa[N][30],dis1[N],trace[N],res2[N];
bool path[1002][1002];
void sang() {
    for (ll i=1;i<=100000;i++) {
        for (ll j=i;j<=100000;j+=i) {
            divv[j].pb(i);
        }
    }
}
bool cmp(ll a,ll b) {
    return num[a] < num[b];
}
void dfs(ll u,ll pre) {
    num[u]=++tim;
    for (auto it : adj[u]) {
        if (it != pre) {
            dis[it]=dis[u]+1;
            pa[it][0]=u;
            dfs(it,u);
        }
    }
}
void prepa() {
    for (ll i=1;i<=__lg(n);i++) {
        for (ll j=1;j<=n;j++) pa[j][i]=pa[pa[j][i-1]][i-1];
    }
}
ll lca(ll u,ll v) {
    if (dis[u] < dis[v]) swap(u,v);
    if (u==v) return u;
    ll l=__lg(dis[u]-dis[v]);
    ll r=dis[u]-dis[v];
    for (ll i=l;i>=0;i--) {
        if ((r>>i)&1) {
            u=pa[u][i];
        }
    }
    if (u==v) return u;
    for (ll i=__lg(dis[u]);i>=0;i--) {
        if (pa[u][i] != pa[v][i]) {
            u=pa[u][i];
            v=pa[v][i];
        }
    }
    return pa[u][0];
}
ll disuv(ll u,ll v) {
    return dis[u]+dis[v]-dis[lca(u,v)];
}

void sub1() {
    for (ll i=1;i<=n;i++) dis1[i]=inf;
    dis1[1]=0;
    queue <ll> ir;
    ir.push(1);
    while (!ir.empty()) {
        ll fr=ir.front();ir.pop();
        for (auto it : adj[fr]) {
            if (dis1[it] > dis1[fr] +1) {
                dis1[it]=dis1[fr]+1;
                trace[it]=fr;
                ir.push(it);
            }
        }
    }
    for (ll i=1;i<=n;i++) {
        memset(path,0,sizeof(path));
        for (ll j=i;j<=n;j+=i) {
            ll ff=j;
            while (ff != 1) {
                path[min(ff,trace[ff])][max(ff,trace[ff])]=true;
                ff=trace[ff];
            }
        }
        for (auto it : st) {
            if (path[it.first][it.second]) {
                res2[i]+=2;
            }
        }
    }
    for (ll i=1;i<=n;i++) {
        cout<<res2[i]<<endl;
    }
    return ;
}
void sub2() {
    for (ll i=1;i<=n;i++) {
        vector <ll> sts;
        for (ll j=i;j<=n;j+=i) {
            sts.pb(j);
        }
        sort(sts.begin(),sts.end(),cmp);
        res[i]=dis[sts[0]];
        for (ll k=1;k<sts.size();k++) {
            res[i]+=dis[sts[k]]-dis[lca(sts[k],sts[k-1])];
        }
    }
    for (ll i=1;i<=n;i++) {
        cout<<res[i]*2<<endl;
    }
    return ;
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
    sang();
    cin>>n;
    for (ll i=1;i<=n-1;i++) {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        st.pb({min(u,v),max(u,v)});
    }
    dfs(1,1);
    prepa();
    if (n <= 100) {
        sub1();
    }
    else {
        sub2();
    }
    return 0;
}
/**
18 10 8 6 8 4 2 2 4 6
*/
