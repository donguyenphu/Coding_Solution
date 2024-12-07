#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=6e5+4;
ll t[N],r[N],dp[N],n;
signed main()
{
    cin>>n;
    for (ll i=1;i<=n;++i) {
        cin>>t[i];
    }
    for (ll j=1;j<n;j++) {
        cin>>r[j];
    }
    dp[1]=t[1]; /// NGUOI 1 CHI CO THE TU MUA VE
    for (ll i=2;i<=n;i++) {
        dp[i]=min(dp[i-1]+t[i],r[i-1]+dp[i-2]);
        /// dp[i-1] +t[i] tuc la thoi gian mua ve cua nguoi i va truong hop f[i-1]
    }
    cout<<dp[n];
}
