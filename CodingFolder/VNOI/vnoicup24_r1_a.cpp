#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll N=2e5+5;
ll a[N],n;
ll t;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  ///  if (fopen("p1.inp","r")) {
 ///       f("p1.inp","r",stdin);
 ///       f("p1.out","w",stdout);
 ///   }
    cin>>t;
    while (t--) {
        ll t1=0,t2=0;
        ll res=0;
       // map <ll,ll> mp;
        cin>>n;
        for (ll i=1;i<=n;i++) {
            cin>>a[i];
            if (a[i]==1) t1++;
            else if (a[i]==2) t2++;
            else {
                t1+=a[i]-2;
                t2++;
            }
        }
        res+=t2/2;
        res+=t1/2;
        cout<<res<<endl;
    }
    return 0;
}
