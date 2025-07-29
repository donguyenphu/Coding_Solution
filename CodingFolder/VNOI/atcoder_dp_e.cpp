#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e2 + 2;
const int K = 1e3 + 2;
int n, weight, w[N], v[N], dp[N][K * N];
long long sum = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("E.INP","r")) {
        freopen("E.INP","r",stdin);
        freopen("E.OUT","w",stdout);
    }
    memset(dp, 0x3f3f, sizeof(dp));
    cin>>n>>weight;
    for (int i = 1; i <= n; i++) {
        cin>>w[i]>>v[i];
        dp[i][0] = 0;
        sum += v[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= v[i]) {
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);
            }
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }
    long long res = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= 1000 * 100; i++) {
                if (dp[j][i] <= weight) {
                    res = max(res, i);
                }
        }
    }
    cout<<res;
    return 0;
}
