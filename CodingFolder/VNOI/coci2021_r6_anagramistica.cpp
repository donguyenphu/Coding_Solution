#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll N=2e3+7;
const ll mod=1e9+7;
ll dp[N][N],n,k,siz=0;
ll bc[N][N],ap[N],st[N];
string a[N];
vector <string> cmress;
map <ll,ll> mp;
ll sq(ll x) {
  return x*x;
}
ll poww(ll a,ll b,ll mod) {
  if (b==0) return 1;
  if (a==1) return b%mod;
  if (b % 2==0) {
    return sq(poww(a,b/2,mod)%mod)%mod;
  }
  else {
    return ((a%mod)*(sq(poww(a,b/2,mod)%mod)%mod)%mod)%mod;
  }
  return 0;
}
void pre() {
  for (ll i=1;i<=2002;i++) {
   bc[i][0]=bc[i][i]=1;
   bc[i][1]=i;
  }
  for (ll i=2;i<=2002;i++) {
    for (ll j=2;j<=2002;j++) {
      if (i > j) {
        bc[i][j]=(bc[i-1][j]%mod+bc[i-1][j-1]%mod)%mod;
      }
    }
  }
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre();
  cin>>n>>k;
  for (ll i=1;i<=n;i++) {
    cin>>a[i];
    sort(a[i].begin(),a[i].end());
    cmress.pb(a[i]);
  }
  sort(cmress.begin(),cmress.end());
  cmress.resize(unique(cmress.begin(),cmress.end())-cmress.begin());
  for (ll i=1;i<=n;i++) {
    st[i]=lower_bound(cmress.begin(),cmress.end(),a[i])-cmress.begin();
    st[i]++;
    siz=max(siz,st[i]);
    ap[st[i]]++;
  }
  sort(st+1,st+n+1);
  // for (ll i=1;i<=n;i++) {
  //   cout<<st[i]<<' ';
  // }
  // cout<<endl;
  // for (ll i=1;i<=n;i++) {
  //   cout<<st[i]<<' '<<ap[st[i]]<<endl;
  // }
  // cout<<endl;
  // for (ll i=0;i<=k;i++) dp[0][i]=1;
  // for (ll i=1;i<=siz;i++) {
  //   cout<<i<<' '<<ap[i]<<endl;
  // }
  ll rem=1e9+7;
  // cout<<siz<<endl;
  dp[0][0]=1;
  // for (ll i=1;i<=siz;i++) dp[i][0]=poww(2,i-1,rem);
  // cout<<bc[6][2]<<endl;
  // cout<<bc[6][1]<<endl;
  // for (ll i=1;i<=k;i++) {
  for (ll j=1;j<=siz;j++) {
    for (ll i=0;i<=k;i++) {
      for (ll rr=0;rr<=ap[j];rr++) {
        ll calc=(rr*(rr-1))/2;
        if (i >= calc) {
          dp[j][i]=(dp[j][i]%mod+(dp[j-1][i-calc]*bc[ap[j]][rr]%mod))%mod;
        }
      }
    }
  }
  // for (ll i=1;i<=siz;i++) cout<<dp[i][k]<<" ";
  // cout<<endl;
  cout<<dp[siz][k];
  return 0;
}
