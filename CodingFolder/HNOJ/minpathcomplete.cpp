/// MAX SUB1
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
const ll N=3e5+4;
ll d[N],a[N];
ll n,m;
ll u,v,w;
const ll inf=1e17;
map <pll,bool> change;
map <pll,ll> ch2;
void di(ll s) {
  fill(d,d+n+5+1,inf);
  d[s]=0;
  priority_queue <pll,vector<pll>,greater<pll>> pq;
  pq.push({0,s});
  while (!pq.empty()) {
    ll v=pq.top().fi;
    ll u=pq.top().se;
    pq.pop();
    if (v != d[u]) continue;
    for (ll i=1;i<=n;i++) {
      if (i != u) {
     ////   ll ch=(change[{i,u}] || change[{u,i}]) ? ch2[{i,u}] : (a[i]+a[u])/(__gcd(a[i],a[u]));
        if (d[i] > d[u] + ch2[{u,i}]) {
          d[i]=d[u]+ch2[{u,i}];
          pq.push({d[i],i});
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
  cin>>n>>m;
  for (ll i=1;i<=n;i++) {
    cin>>a[i];
  }
  for (ll i=1;i<=n;i++) {
    for (ll j=1;j<=n;j++) {
      if (i != j) {
        ch2[{i,j}]=(a[i]+a[j])/(__gcd(a[i],a[j]));
      }
    }
  }
  for (ll i=1;i<=m;i++) {
    cin>>u>>v>>w;
 //   ch2[{u,v}]=ch2[{v,u}]=w;
    ch2[{u,v}]=ch2[{v,u}]=min(ch2[{u,v}],w);
  }
  di(1);
  for (ll i=1;i<=n;i++) {
    cout<<d[i]<<' ';
  }
  return 0;
}
