#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int mod = 2111992;
const int N = 1e4 + 3;
const int K =  1e1 + 3;
int n, a[N], k;
int dp[N][K];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    memset(dp, -0x3f3f3f, sizeof(dp));
    dp[1][1] = a[1];
    dp[0][0] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            if (i - j == 0) {
                dp[i][j] = max(dp[i][j], dp[0][0] + a[i]);
            }
            else if (i > j) {
                for (int h = 1; h <= min(k, i-j); h++) {
                    dp[i][j] = max(dp[i][j], dp[i-j][h] + a[i]);
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(k, i); j++) {
            res = max(res, dp[i][j]);
        }
    }
    cout<<res;
    return 0;
}
