#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
#define NAME "NHAPVAODAY"
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define maximize(a,b) a=max(a,b)
#define minimize(a,b) a=min(a,b)
using namespace std;
const ll N=1e5+3;
ll a[N],dp[N],n;
signed main()
{
    cin.tie()->sync_with_stdio(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    if (fopen(NAME".inp","r")) {
        f(NAME".inp","r",stdin);
        f(NAME".out","w",stdout);
    }
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    dp[1]=0;
    dp[2]=abs(a[2]-a[1]);
    dp[3]=abs(a[3]-a[1]);
    for (ll i=4;i<=n;i++) {
        dp[i]=min(  dp[i-1]+abs(a[i]-a[i-1])  ,dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n];
}
