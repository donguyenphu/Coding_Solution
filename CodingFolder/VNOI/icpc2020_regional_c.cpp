#include <bits/stdc++.h>
#define ll long long
using namespace std;
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  while (t--) {
    ll a,b,c1,c2;
    cin>>a>>b>>c1>>c2;
    ll ff=max(c1,c2);
    ll ss=min(c1,c2);
    ll k;
    ll cnt1=0,cnt2=0;
    cin>>k;
    for (ll i=1;i<=k;i++) {
      ll x,y;
      cin>>x>>y;
      if (a*x+b*y >= ff) cnt1++;
      if (a*x+b*y <= ss) cnt2++;
    }
    cout<<(cnt1==k || cnt2==k ? "NO" : "YES")<<endl;
  }
  return 0;
}
