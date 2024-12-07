#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e4+3;
const ll inf=1e16;
struct chef {
  ll sum,pre,suf,best;
};
chef st[N<<2];
ll n,a[N],l,r,q;
chef join(chef l,chef r) {
  chef res;
  res.sum=l.sum+r.sum;
  res.pre=max({l.pre,l.sum+r.pre});
  res.suf=max({r.suf,l.suf+r.sum});
  res.best=max({max(l.best,r.best),l.suf+r.pre});
  return res;
}
void build(ll id,ll l,ll r) {
  if (l==r) {
    st[id].sum=st[id].pre=st[id].suf=st[id].best=a[l];
    return ;
  }
  ll mid=(l+r)>>1;
  build(2*id,l,mid);
  build(2*id+1,mid+1,r);
  st[id]=join(st[2*id],st[2*id+1]);
}
chef get(ll id,ll l,ll r,ll u,ll v) {
  if (v < l || u > r) {
    return {0LL,-inf,-inf,-inf};
  }
  if (u <= l && v >= r) {
    return st[id];
  }
  ll mid=(l+r)>>1;
  return join(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n;
  for (ll i=1;i<=n;i++) {
    cin>>a[i];
  }
  build(1,1,n);
  cin>>q;
  for (ll i=1;i<=q;i++) {
    cin>>l>>r;
    cout<<get(1,1,n,l,r).best<<endl;
  }
  return 0;
}
