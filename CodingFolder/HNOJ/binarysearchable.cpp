/// MAX SUB4
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
using namespace std;
const ll N=3e6+5;
const ll mod=1e9+7;
ll a[N],n;
ll dp1[N],dp2[N];
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  /// try hard sub4
  cin>>n;
  for (ll i=1;i<=n;i++) {
    cin>>a[i];
  }
  ll ff=0;
  for (ll i=1;i<=n;i++) {
    dp1[i]=1;
    for (ll j=1;j<i;j++) {
      if (a[i] >= a[j]) {
        dp1[i]=(dp1[i]+dp1[j])%mod;;
      }
    }
    ff=(ff+dp1[i])%mod;
  }
  for (ll i=1;i<=n;i++) {
    dp2[i]=1;
    for (ll j=1;j<i;j++) {
      if (a[i] <= a[j]) {
        dp2[i]=(dp2[i]+dp2[j])%mod;
      }
    }
    ff=(ff+dp2[i])%mod;
  }
  cout<<(ff+1-n)%mod<<endl;
  return 0;
}
