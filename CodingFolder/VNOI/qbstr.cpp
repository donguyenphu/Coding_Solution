#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5e3 + 1;
int dp[N][N];
string a, b;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a;
    cin>>b;
    int n = a.size();
    int m = b.size();
    a = " "+a;
    b = " "+b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
