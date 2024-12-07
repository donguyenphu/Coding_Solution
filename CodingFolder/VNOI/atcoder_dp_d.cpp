#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
using namespace std;
const ll N=1e2+4;
const ll F=1e5+4;
ll w[N],v[N];
ll dp[N][F];
ll n,k;
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
    for (ll i=1;i<=n;++i) {
        cin>>w[i]>>v[i];
    }
    for (ll i=1;i<=k;i++){
        dp[0][i]=0;
    }
    for (ll i=1;i<=n;i++) {
        dp[i][0]=0;
    }
    for (ll i=1;i<=k;i++) {
        for (ll j=1;j<=n;j++) {
            if (w[j] <= i) {
                dp[j][i]=max(dp[j-1][i],dp[j-1][i-w[j]]+v[j]);
            }
            else {
                dp[j][i]=dp[j-1][i];
            }
        }
    }
  /**  for (ll i=1;i<=k;i++) {
        for (ll j=1;j<=n;j++) {
            cout<<dp[j][i]<<" ";
        }
        cout<<endl;
    } */
    cout<<dp[n][k];
    return 0;
}
