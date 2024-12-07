#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=4e2+3;
const ll LG=2e1+3;
const ll inf=3e18;
ll rmq[N][N];
ll n,k,a[N];
ll f[N][N];
ll pre[N];
ll st[N*4];
ll get(ll l,ll r) {
    ll kq=__lg(r-l+1);
    return max(rmq[l][kq],rmq[r-(1<<(kq))+1][kq]);
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>k;
  for (ll i=0;i<=n;i++) {
    for (ll j=0;j<=k;j++) f[i][j]=inf;
  }
  // cout<<k<<endl;
  for (ll i=1;i<=n;i++) {
    cin>>a[i];
    pre[i]=pre[i-1]+a[i];
    rmq[i][0]=a[i];
  }
  // for (ll i=1;i<=n;i++) {
  //   cout<<pre[i]<<' ';
  // }
  // cout<<endl;
  ll val=__lg(n);
  // cout<<val<<endl;
  for (ll gg=1;gg<=val;gg++) {
    for (ll i=1;i + (1<<gg) -1 <=n;i++) {
      rmq[i][gg]=max(rmq[i][gg-1],rmq[i+(1<<(gg-1))][gg-1]);
    }
  }
  // ll maxx=0;
  for (ll i=1;i<=n;i++) {
    ll maxx=get(1,i);
    f[i][0]=i*maxx-pre[i];
  }
  // for (ll i=1;i<=n;i++) {
  //   cout<<f[i][0]<<' ';
  // }
  // cout<<endl;
  // cout<<k<<endl;
  // f[1][1]=f[1][0];
  for (ll i=1;i<=n;i++) {
    for (ll j=1;j<=i;j++) {
      // if ()
      for (ll rr=1;rr<=min(j,k);rr++) {
        ll ma=get(j,i);
        ll val=f[j-1][rr-1]+ma*(i-j+1)-(pre[i]-pre[j-1]);
        f[i][rr]=min(f[i][rr],val);
      }
    }
  }
  ll mi=inf;
  for (ll i=0;i<=k;i++) {
    mi=min(mi,f[n][i]);
    // cout<<f[n][i]<<' ';
  }
  // cout<<endl;
  cout<<mi;
  return 0;
}
