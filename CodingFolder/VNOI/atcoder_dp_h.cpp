#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
using namespace std;
ll n,k;
const ll N=1e5+3;
const ll F=1e2+4;
ll a[N];
ll dp[N];
const ll INF=1e12;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    cin>>n>>k;
    for (ll i=0;i<=n;++i) {
        dp[i]=INF;
    }
 /**   for (ll i=1;i<=n;++i) {
        if (dp[i] == INF) {
            cout<<-1<<" ";
        }
        else cout<<dp[i]<<" ";
    } */
    for (ll i=1;i<=n;++i) {
        cin>>a[i];
    }
   // dp[0]=0;
    dp[1]=0;
    dp[2]=abs(a[2]-a[1]);
    for (ll i=3;i<=n;i++) {
        for (ll j=1;j<=k;j++) {
            if (i > j) {
                dp[i]=min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
            }
        }
    }
 //   for (ll i=1;i<=n;i++) {
   //     cout<<dp[i]<<" ";
   // }
    cout<<dp[n];
    return 0;
}
