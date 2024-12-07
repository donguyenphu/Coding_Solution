#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define n row
#define m column
using namespace std;
const ll N=1e2+16;
ll a[N][N],dp[N][N],n,m;
ll maxn=-1e9;
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            cin>>a[i][j];
        }
    }
    for (ll i=0;i<m;i++) dp[0][i]=dp[n+1][i]=-1e9;
    for (ll j=1;j<=m;j++) { /// chay tu cot 2
        for (ll i=1;i<=n;i++) {
            dp[i][j]=max(max(dp[i-1][j-1],dp[i][j-1]),dp[i+1][j-1])+a[i][j];
        }
    }
    for (ll i=1;i<=n;i++) {
        maxn=max(maxn,dp[i][m]);
    }
    cout<<maxn<<endl;
}
    /*                                5 7
                                  1  2 3 4 5 6 7
                               ----------------
                              0   A  A A A A A A
                              1   9 -2 6 2 1 3 4
                              2   0 -1 6 7 1 3 3
                              3   8 -2 8 2 5 3 2
                              4   1 -1 6 2 1 6 1
                              5   7 -2 6 2 1 3 7
                              n+1 A  A A A A A A
                                */

/// row :run 1-> 5
/// column :run 2->7
