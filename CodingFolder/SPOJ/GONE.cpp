#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll N=3e1+2;
const ll F=1e2+2;
const ll S=2e2+2;
ll dp[N][F][4],a,b,dig[N],k,t;
bool prim[S];
map <ll,ll> mp;
void sang(ll n) {
  memset(prim,true,sizeof(prim));
  prim[0]=prim[1]=false;
  for (ll i=2;i*i<=n;i++) {
    if (prim[i]==true) {
      for (ll j=i*i;j<=n;j+=i) prim[j]=false;
    }
  }
}
ll back(ll i,ll sum,bool lower) {
  ///  map <ll,ll> mp;
  if (i==0) {
  //  return ((!mp[sum] && prim[sum]) ? 1 : 0);
  //  mp[sum]++;
   return prim[sum];
  }
  ll &res=dp[i][sum][lower];
  if (res != -1) return res;
  res=0;
  ll lim=(lower ? 9 : dig[i]);
  for (ll j=0;j<=lim;j++) {
    bool ok2=(lower || (j < lim));
    res+=back(i-1,sum+j,ok2);
  }
  return res;
}
ll calc(ll n) {
  if (!n) return 0;
  memset(dig,0,sizeof(dig));
  memset(dp,-1,sizeof(dp));
  ll tm=0,ff=n;
  while (ff > 0) {
 ///   tm++;
    dig[++tm]=ff%10;
    ff/=10;
  }
  return back(tm,0,false);
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sang(400);
  ll t;
  cin>>t;
  while (t--) {
    cin>>a>>b;
    cout<<calc(b)-calc(a-1)<<'\n';
  }
  return 0;
}
