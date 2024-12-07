#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e3+4;
ll q,val;
string s;
ll a[N];
ll n;
ll diff[N][N/2+40];
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("VIRUS.INP","r")) {
    freopen("VIRUS.INP","r",stdin);
    freopen("VIRUS.OUT","w",stdout);
  }
  cin>>q;
  // cout<<q<<endl;
  cin>>s;
  n=s.size();
  ll tm=0;
  for (ll i=0;i<n;i++) a[++tm]=(s[i]-'a')+1;
  // for (ll i=1;i<=n;i++) {
  //   cout<<a[i]<<' ';
  // }
  // cout<<endl;
  for (ll i=1;i<=q;i++) {
    cin>>val;
    ll ans=-1;
    for (ll j=1;j<=tm/2;j++) {
      bool ok=false;
      ll cnt=0;
      for (ll g=1;g<=tm-j;g++) {
        if (g < j) cnt+=(a[g] != a[g+j]);
        else {
          if (g==j) {
            cnt+=a[g] != a[g+j];
            if (cnt <= val) ok=true;
          }
          else {
            cnt-=(a[g] != a[g-j]);
            cnt+=(a[g] != a[g+j]);
            if (cnt <= val) ok=true;
          }
        }
      }
      if (ok) ans=max(ans,j);
    }
    cout<<(ans==-1 ? 0 : ans)<<endl;
  }
  return 0;
}
