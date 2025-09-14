#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long n, s, a[101],dp[101][1000001];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    cin>>n>>s;
    for (long long i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            dp[i][j] = dp[i-1][j] % mod;
            if (j >= a[i]) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i]];
                if (dp[i][j] >= mod) dp[i][j] -=mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<dp[n][s];
    return 0;
}
