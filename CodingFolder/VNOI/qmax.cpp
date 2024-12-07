#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e4+3;
const ll inf=1e14;
ll a[N],st[N<<2],n,m,p,laz[N<<2],q;
void down(ll id) {
  st[id<<1]+=laz[id];
  st[id<<1|1]+=laz[id];
  laz[id<<1]+=laz[id];
  laz[id<<1|1]+=laz[id];
  laz[id]=0;
  return ;
}
ll get(ll id,ll l,ll r,ll u,ll v) {
  if (v < l || u > r) {
    return -inf;
  }
  if (u <= l && v >= r) {
    return st[id];
  }
  down(id);
  ll mid=(l+r)>>1;
  return max(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v));
}
void upd(ll id,ll l,ll r,ll u,ll v,ll val) {
  if (v < l || u > r) {
    return ;
  }
  if (u <= l && v >= r) {
    laz[id]+=val;
    st[id]+=val;
    return ;
  }
  down(id);
  ll mid=(l+r)>>1;
  upd(id<<1,l,mid,u,v,val);
  upd(id<<1|1,mid+1,r,u,v,val);
  st[id]=max(st[id<<1],st[id<<1|1]);
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for (ll i=1;i<=m;i++) {
    ll l,r,val;
    cin>>l>>r>>val;
    upd(1,1,n,l,r,val);
  }
  cin>>q;
  for (ll i=1;i<=q;i++) {
    ll c1,c2;
    cin>>c1>>c2;
    cout<<get(1,1,n,c1,c2)<<endl;
  }
  return 0;
}
