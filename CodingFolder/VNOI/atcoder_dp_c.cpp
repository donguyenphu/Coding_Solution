#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+4;
ll a[N],b[N],c[N],n;
ll dp[N][5];
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
        cin>>a[i]>>b[i]>>c[i];
    }
    dp[1][0]=a[1];
    dp[1][1]=b[1];
    dp[1][2]=c[1];
    for (ll i=2;i<=n;i++) {
        dp[i][0]=max(dp[i][0],a[i]+dp[i-1][1]);
        dp[i][0]=max(dp[i][0],a[i]+dp[i-1][2]);
        dp[i][1]=max(dp[i][1],b[i]+dp[i-1][0]);
        dp[i][1]=max(dp[i][1],b[i]+dp[i-1][2]);
        dp[i][2]=max(dp[i][2],c[i]+dp[i-1][1]);
        dp[i][2]=max(dp[i][2],c[i]+dp[i-1][0]);
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]});
    return 0;
}
