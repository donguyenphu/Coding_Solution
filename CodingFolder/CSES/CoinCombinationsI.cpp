#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long n, s, a[102],dp[1000002];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>s;
    for (long long i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    dp[0] = 1;
    for (long long i = 1; i <= s; i++)
    {
        for (long long j = 1; j <= n; j++)
        {
            if (a[j] <= i)
            {
                dp[i] += dp[i - a[j]];
                if (dp[i] >= mod) dp[i] -= mod;
            }
        }
    }
    cout<<dp[s];
    return 0;
}
