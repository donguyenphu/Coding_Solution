#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
#define fi first
#define se second
using namespace std;
const ll N=25e3+5;
ll a[N],dp[N];
ll n;
signed main()
{   /// 7
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    cin>>n;
    for (ll i=1;i<=n-1;i++) {
        cin>>a[i];
    }
    dp[1]=0;
    dp[2]=a[1];
    dp[3]=a[1]+a[2];
    dp[4]=a[1]+a[3];
    for (ll i=5;i<=n;i++) {
        dp[i]=min(a[i-1]+a[i-2]+dp[i-3],a[i-1]+dp[i-2]);
    }
    cout<<dp[n]<<endl;
}
