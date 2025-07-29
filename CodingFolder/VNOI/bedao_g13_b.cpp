#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 3;
const long long lim = -2e16;
int n, a[N], dp[N][3][3], pre[N];
/// xet 1...i, hien co bao nhieu nhom, dong hay mo
int sum (int l, int r) {
    return pre[r] - pre[l - 1];
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
        dp[i][0][0] = dp[i][1][0] = dp[i][2][0] = lim;
        dp[i][0][1] = dp[i][1][1] = dp[i][2][1] = lim;
    }
    dp[0][0][0] = dp[0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = dp[i-1][0][0] + a[i];
        dp[i][0][1] = dp[i-1][0][1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, 2*1LL) ; j++) {
            /// open
            dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + -1 * a[i]);
            if (i-1 >= j) {
                /// skip
                dp[i][j][0] = max({dp[i][j][0], dp[i-1][j][0] + a[i], dp[i-1][j][1] + a[i]});
                /// con
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + -1 * a[i]);
                /// close
                dp[i][j][0] = max({dp[i][j][0], dp[i-1][j][1] + -1 * a[i], dp[i-1][j][1] + -1 * a[i]});
            }
        }
    }
    long long max1 = max({dp[n][0][0], dp[n][1][0], dp[n][2][0]});
    cout<<max1;
    return 0;
}
