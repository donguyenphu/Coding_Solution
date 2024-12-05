#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
using namespace std;
const ll N=2e5+4;
ll a[N],b[N],n,m;
ll pre1[N],pre2[N];
ll s=0;
bool mark[N];
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for (ll i=1;i<=n;i++) {
    cin>>a[i];
  }
  for (ll i=1;i<=m;i++) {
    cin>>b[i];
    s+=b[i];
    pre2[i]=pre2[i-1]+b[i];
  }
  if (n==1) {
    cout<<a[1]+b[1]<<endl;
    exit(0);
  }
  else {
 //   ll check=min(m,n-m+1);
    if (n-m+1 < m) {  /// ko du
     ll check=n-m+1;
     for (ll i=1;i<check;i++) {
       a[i]+=pre2[i];
     }
     ll ff=m;
     for (ll i=n;i>=n-(check-1)+1;i--) {
       a[i]+=pre2[m]-pre2[ff-1];
       ff--;
     }
     for (ll i=check;i<=n-(check-1);i++) {
       a[i]+=pre2[i]-pre2[i-check];
     }
     for (ll i=1;i<=n;i++) {
       cout<<a[i]<<' ';
     }
    }
    else { /// du
 ///     cout<<1<<endl;
      for (ll i=1;i<m;i++) {
        a[i]+=pre2[i];
      }
      ll ff=m;
   //   cout<<(n-(m-1)+1)<<endl;

      for (ll i=n;i>=n-(m-1)+1;i--) {
        a[i]+=pre2[m]-pre2[ff-1];
        ff--;
      }
      for (ll i=m;i<=n-(m-1);i++) {
        a[i]+=s;
      }
      for (ll i=1;i<=n;i++) {
        cout<<a[i]<<' ';
      }
    }
    exit(0);
  }

//  ll ff=n-m+1;

  return 0;
}
