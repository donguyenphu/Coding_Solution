#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
using namespace std;
const ll N=1e5+4;
ll a[N],n;
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("p1.inp","r")) {
    f("p1.inp","r",stdin);
    f("p1.out","w",stdout);
  }
  cin>>n;
  ll s=0;
  ll lim=0;
  if (n%2) {
    lim=5*n-n/2;
  }
  else {
    lim=5*n-n/2;
  }
  for (ll i=1;i<=n;i++) {
    cin>>a[i];s+=a[i];
  }
  sort(a+1,a+n+1);
  if (s>=lim) {
    cout<<0<<endl;
  }
  else {
    ll tm=0;
    for (ll i=1;i<=n;i++) {
      s+=abs(5-a[i]);
      tm++;
      if (s >= lim) {
        cout<<tm<<endl;
        exit(0);
      }
    }
  }
  return 0;
}
