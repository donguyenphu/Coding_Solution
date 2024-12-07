#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
using namespace std;
const ll N=1e6+3;
ll a[N],n,pre[N];
ll maxn=0;
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("p1.inp","r")) {
    freopen("p1.inp","r",stdin);
    freopen("p1.out","w",stdout);
  }
  cin>>n;
  for (ll i=1;i<=n;i++) {
    cin>>a[i];
    pre[i]=pre[i-1]+a[i];
  }
  for (ll i=1;i<=n;i++) {
    ll l=1,r=n;
    while (l<=r && l <=i && r >=i && r >= 1 && l <= n) {
      if (pre[r]-pre[l-1]==(pre[i]-pre[l-1])*2) {
        maxn=max(maxn,r-l+1);
        break;
      }
      else if (pre[r]-pre[l-1] > (pre[i]-pre[l-1])*2) {
        r--;
      }
      else l++;
    }
  }
  cout<<maxn;
  return 0;
}
