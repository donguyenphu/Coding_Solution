#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+2;
const ll blocks=1e2+2;
ll dp[N][blocks];
ll rm[N][32];
ll a[N];
ll n,k;
void build(ll lgg) {
    for (ll i=1;i<=lgg;i++) {
        for (ll j=1;j+(1<<i)-1<=n;j++) {
            rm[j][i]=max(rm[j][i-1],rm[j+(1<<(i-1))][i-1]);
        }
    }
}
ll get(ll l,ll r) {
    ll k=__lg(r-l+1);
    return max(rm[l][k],rm[r-(1<<k)+1][k]);
}
ll minn[N];
stack <pll> st[blocks];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
      freopen("p1.inp","r",stdin);
      freopen("p1.out","w",stdout);
    }
    if (fopen("blocks.in","r")) {
        freopen("blocks.in","r",stdin);
        freopen("blocks.out","w",stdout);
    }
    memset(dp,0x3f3f,sizeof(dp));
    cin>>n>>k;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
        rm[i][0]=a[i];
    }
    build(__lg(n));
    for (ll i=1;i<=n;i++) dp[i][1]=get(1,i);
   /// for (ll i=1;i<=n;i++) cout<<dp[i][1]<<' ';
  ///  st[1].push({a[1],1});
    for (ll i=2;i<=k;i++) {
    ///  st[i].push({a[1],1});
      for (ll j=i;j<=n;j++) {
      //  dp[j][i]=dp[j-1][i-1]+a[i]; /// 1 elm
        ll init=dp[j-1][i-1];
        /// xet cac ptu tang dan
        while (st[i].size() && a[st[i].top().second] <= a[j]) {
            init=min(init,st[i].top().first);
            st[i].pop();
        }
        if (st[i].size()) {
          dp[j][i]=dp[st[i].top().second][i];
        }
        dp[j][i]=min(dp[j][i],init+a[j]);
        st[i].push({init,j});
      }
    }
    cout<<dp[n][k];
    return 0;
}
