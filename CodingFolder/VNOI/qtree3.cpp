#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+3;
ll n,t,u,v,i,q,tim=0;
vector <ll> adj[N];
bool mark[N];
ll lab[N];
ll laz[N<<2],st[N<<2],child[N];
ll pa[N][27],height[N],og[N];
void down(ll id,ll l,ll r) {
    ll mid=(l+r)>>1;
    st[2*id]+=(mid-l+1)*laz[id];
    st[2*id+1]+=(r-mid)*laz[id];
    laz[2*id]+=laz[id];
    laz[2*id+1]+=laz[id];
    laz[id]=0;
    return ;
}
void check(ll u,ll pre) {
    lab[u]=++tim;
    og[lab[u]]=u;
    for (auto it : adj[u]) {
        if (it==pre) continue;
        else {
            check(it,u);
        }
    }
}
void dfs(ll u,ll pre) {
    for (auto it : adj[u]) {
        if (it==pre) continue;
        else {
            pa[lab[it]][0]=lab[u];
            height[lab[it]]=height[lab[u]]+1;
            dfs(it,u);
        }
    }
}
void cnt(ll u,ll pre) {
    for (auto it : adj[u]) {
        if (it==pre) continue;
        else {
            child[lab[u]]++;

            cnt(it,u);

            child[lab[u]]+=child[lab[it]];
        }
    }
}
void up(ll id,ll l,ll r,ll u,ll v,ll val){
    if (v < l || u > r) return ;
    if (u <= l && v >= r) {
        laz[id]+=val;
        st[id]+=(r-l+1)*val;
        return ;
    }
    down(id,l,r);
    ll mid=(l+r)>>1;
    up(2*id,l,mid,u,v,val);
    up(2*id+1,mid+1,r,u,v,val);
    st[id]=st[2*id]+st[2*id+1];
}
ll get(ll id,ll l,ll r,ll u,ll v) {
    if (v < l || u > r) return 0;
    if (u <= l && v >= r) return st[id];
    down(id,l,r);
    ll mid=(l+r)>>1;
    return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
}
ll conpa(ll u,ll dis) {
    ll lgg=__lg(dis);
    for (ll j=0;j<=lgg;j++) {
        if ((dis>>j)&1) {
            u=pa[u][j];
        }
    }
    return u;
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
    memset(lab,0,sizeof(lab));
    cin>>n>>q;
    for (ll i=1;i<=n-1;i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    check(1,-1);
    dfs(1,-1);
    cnt(1,-1);
  /*  for (ll i=1;i<=n;i++) {
        cout<<lab[i]<<' '<<child[lab[i]]<<endl;
    } */
   // cout<<endl;
   /// cout<<__lg(n)<<endl;
    for (ll i=1;i<=__lg(n);i++) {
        for (ll j=1;j<=n;j++) {
            pa[j][i]=pa[pa[j][i-1]][i-1];
        }
    }
  ///  cout<<pa[lab[3]][0]<<endl;
  ///  cout<<pa[lab[6]][2]<<endl;
  /**  for (ll i=1;i<=n;i++) {
        for (ll j=0;j<=20;j++) {
            cout<<pa[i][j]<<' ';
        }
        cout<<endl;
    } */
    for (ll gg=1;gg<=q;gg++) {
        cin>>t>>i;
        if (t==0) {
          ///  cout<<i<<' '<<lab[i]<<' '<<child[lab[i]]<<endl;
            if (!mark[i]) {
                mark[i]=true;
                up(1,1,n,lab[i],lab[i]+child[lab[i]],1);
            }
            else if (mark[i]) {
                mark[i]=false;
                up(1,1,n,lab[i],lab[i]+child[lab[i]],-1);
            }
        }
        else {
            ll fac=lab[i];
            ll ans=-1;
            ll l=1,r=height[fac];
         ///   cout<<i<<' '<<fac<<' '<<r<<endl;
            while (l <= r) {
                ll mid=(l+r)>>1;
                if (get(1,1,n,conpa(fac,mid),conpa(fac,mid))) {
                    ans=conpa(fac,mid);
                    l=mid+1;
                }
                else r=mid-1;
            }
            if (ans != -1) {
                cout<<og[ans]<<endl;
            }
            else {
                cout<<(get(1,1,n,fac,fac) ? i : -1)<<endl;
            }
        }

    }
    return 0;
}
