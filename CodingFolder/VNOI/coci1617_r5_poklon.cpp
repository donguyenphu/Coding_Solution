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
const ll N=1e6+4;
ll a[N],cnt[N],bit[N];
ll d[N][10],dd[10][N];

vector <pll> qr[N];
ll n,q,u,v;
map <ll,vector<ll>> mp;
map <ll,ll> elm;
ll ans[N];
vector <ll> rrh;
vector <ll> no;
void upd(ll u,ll val) {
  ll idx=u;
  while (idx <= n) {
    bit[idx]+=val;
    idx+=(idx & (-idx));
  }
}
void qry(ll u,ll v) {
  /// chi xet tong la 4 con dau tien, tinh ca con u
  /// qry(i , a[i])
  /// 0 1 2 3
  if (!cnt[v]) { /// 0-> 0
    /// continue
    cnt[v]++;
    d[v][0]=u;
    return ;
  }
  else if (cnt[v]==1) { /// 0 0 -> 1 0
    cnt[v]++;
    d[v][1]=d[v][0];
    d[v][0]=u;
    upd(d[v][1],1);
    return ;
  }
  else if (cnt[v]==2) { // 1 0 0 -> -1 1 0
    cnt[v]++;
    d[v][2]=d[v][1];
    d[v][1]=d[v][0];
    d[v][0]=u;
    upd(d[v][1],1);
    upd(d[v][2],-2);
    return ;
  }
  else if (cnt[v]==3) { /// -1 1 0 0 -> 0 -1 1 0
    cnt[v]++;
    d[v][3]=d[v][2];
    d[v][2]=d[v][1];
    d[v][1]=d[v][0];
    d[v][0]=u;
    upd(d[v][1],1);
    upd(d[v][2],-2);
    upd(d[v][3],1);
    return ;
  }
  else { /// 0 -1 1 0 0 ->  0 0 -1 1 0 , 0 0 -1 1 0 0 -> 0 0 0 -1 1 0
        ///  0 0 -1 1 0                , 0 0 0 -1 1 0
    cnt[v]++;
    d[v][3]=d[v][2];
    d[v][2]=d[v][1];
    d[v][1]=d[v][0];
    d[v][0]=u;
    upd(d[v][1],1);
    upd(d[v][2],-2);
    upd(d[v][3],1);
    return ;
  }
  return ;
}
// void qry(ll i,ll val) {
//   ll x=dd[0][val];
//   dd[0][val]=i;
//   if(!x) return ;
//   upd(x,1);
//   ll y=dd[1][val];
//   dd[1][val]=x;
//   if(!y) return ;
//   upd(y,-2);
//   ll z=dd[2][val];
//   dd[2][val]=y;
//   if(!z) return ;
//   upd(z,1);
//   return ;
// }
ll get(ll u) {
  ll ans = 0 , idx = u;
  while (idx > 0) {
    ans+=bit[idx];
    idx -=(idx & (-idx));
  }
  return ans;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // memset(bit,0,sizeof(bit));
  cin>>n>>q;
  for (ll i=1;i<=n;i++) {
    cin>>a[i];
    rrh.pb(a[i]);
  }

  sort(rrh.begin(),rrh.end());
  rrh.resize(unique(rrh.begin(),rrh.end())-rrh.begin());
  for (ll i=1;i<=n;i++) {
    a[i]=(lower_bound(rrh.begin(),rrh.end(),a[i])-rrh.begin())+1;
  }

  for (ll i=1;i<=q;i++) {
    cin>>u>>v;
    qr[v].pb({u,i});
  }
  for (ll i=1;i<=n;i++) {
    qry(i,a[i]);
    for (auto it : qr[i]) {
      ans[it.se]=get(i)-get(it.fi-1);
    }
  }
  // for (ll i=1;i<=n;i++) {
  //   cout<<get(i)<<endl;
  // }
  // cout<<endl;
  for (ll i=1;i<=q;i++) {
    cout<<ans[i]<<endl;
  }

  return 0;
}
