#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+2;
const ll blocks=1e2+2;
ll dp[N][blocks];
ll rm[N][32];
ll a[N];
ll n,k;
void build(ll lgg) {
    for (ll i=1;i<=lgg;i++) {
        for (ll j=1;j+(1<<i)-1<=n;j++) {
            rm[j][i]=max(rm[j][i-1],rm[j+(1<<(i-1))][i-1]);
        }
    }
}
ll get(ll l,ll r) {
    ll k=__lg(r-l+1);
    return max(rm[l][k],rm[r-(1<<k)+1][k]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("blocks.in","r")) {
        freopen("blocks.in","r",stdin);
        freopen("blocks.out","w",stdout);
    }
    memset(dp,0x3f3f,sizeof(dp));
    cin>>n>>k;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
        rm[i][0]=a[i];
    }
    build(__lg(n));
    for (ll i=1;i<=n;i++) {
        dp[i][1]=get(1,i);
    }
    for (ll i=2;i<=n;i++) {
        for (ll j=2;j<=min(i,k);j++) {
            for (ll g=j-1;g<=i-1;g++) {
                dp[i][j]=min(dp[i][j],dp[g][j-1]+get(g+1,i));
            }
        }
    }
    cout<<dp[n][k];
    return 0;
}
