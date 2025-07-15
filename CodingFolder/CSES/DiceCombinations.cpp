#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define f freopen
#define MOD 1000000007
using namespace std;
const ll N=1e6+4;
ll dp[N];
ll n;
signed main()
{
    cin>>n;
    dp[0]=1; /// ko tung
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=6;j++) {
            if (i>=j) {
                dp[i]=(dp[i]+dp[i-j])%MOD;
            }
        }
    }
    cout<<dp[n];
}
