#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e4+2;
const ll K=1e3+2;
ll dp[N],n,k,rm[N][30],a[N];
ll pre[N];
void build(ll k) {
    for (ll i=1;i<=k;i++) {
        for (ll j=1;j+(1<<i)-1<=n;j++) {
            rm[j][i]=max(rm[j][i-1],rm[j+(1<<(i-1))][i-1]);
        }
    }
}
ll get(ll l,ll r) {
    ll siz=__lg(r-l+1);
    return max(rm[l][siz],rm[r-(1<<(siz))+1][siz]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    cin>>n>>k;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
        rm[i][0]=a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll val=log2(n);
 ///   cout<<val<<endl;
    build(val);
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=k;j++) {
            if (i >= j) {
                dp[i]=max(dp[i],dp[i-j]+j*get(i-j+1,i));
            }
        }
    }
    cout<<dp[n];
    return 0;
}
