#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e6 + 2;
int n, a[N], b[N], dp[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("WORK.INP","r")) {
        freopen("WORK.INP","r",stdin);
        freopen("WORK.OUT","w",stdout);
    }
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for (int i = 1; i <= n-1; i++) {
        cin>>b[i];
    }
    memset(dp, 0x3f3f, sizeof(dp));
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i], dp[i-1] + a[i]);
        dp[i] = min(dp[i], dp[i-2] + b[i - 1]);
    }
    cout<<dp[n];
    return 0;
}
