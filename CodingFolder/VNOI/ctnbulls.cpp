#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int mod = 2111992;
const int N = 1e5 + 3;
int n, k;
int dp[N][2];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= k + 1) {
            dp[i][0] = 1;
            dp[i][1] = i % mod;
        }
        else {
            dp[i][0] += (dp[i-k-1][0]%mod + dp[i-k-1][1]%mod) % mod;
            dp[i][1] += (dp[i-1][0]%mod + dp[i-1][1]%mod) % mod;
        }
    }
    cout<<(dp[n][0] % mod + dp[n][1] % mod)%mod;
    return 0;
}
