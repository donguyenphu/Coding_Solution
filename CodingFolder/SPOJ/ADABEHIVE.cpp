#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2002;
ll bit[N][N];
ll n,m,a[N][N],q;
ll t,i1,i2,j1,j2;
void up(ll u,ll v,ll val){
    for (ll i=u;i<=n;i+=i & (-i)) {
        for (ll j=v;j<=m;j+= j & (-j)) {
            bit[i][j]+=val;
        }
    }
}
ll get(ll u,ll v) {
    if (!u || !v) return 0;
    ll s=0;
    for (ll i=u;i>=1;i-= i & (-i)) {
        for (ll j=v;j>=1;j-= j & (-j)) {
            s+=bit[i][j];
        }
    }
    return s;
}
ll qr(ll i1,ll i2,ll j1,ll j2) {
    return get(i1,j2)-get(j1-1,i2)-get(i1-1,j2)+get(j1-1,i2-1);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            cin>>a[i][j];
            up(i,j,a[i][j]);
        }
    }
    for (ll i=1;i<=q;i++) {
        cin>>t1;
        if (t1==1) {
            cin>>i1>>i2>>j1;
        }
        else {
            cin>>i1>>i2>>j1>>j2;
            cout<<qr(i1,i2,j1,j2)<<endl;
        }
    }
    return 0;
}
