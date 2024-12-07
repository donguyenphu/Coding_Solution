#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=2e5+4;
ll n,q,a[N],l,r,st[N][5];
void build(ll id,ll l,ll r) {
    if (l==r) {
        st[id][0]=st[id][1]=a[l];
        return ;
    }
    ll mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id][0]=min(st[2*id][0],st[2*id+1][0]);
    st[id][1]=max(st[2*id][1],st[2*id+1][1]);
}
ll get1(ll id,ll l,ll r,ll u,ll v) {
    if (v < l || u > r) return inf;
    if (u <= l && v >= r) return st[id][0];
    ll mid=(l+r)>>1;
    return min(get1(2*id,l,mid,u,v),get1(2*id+1,mid+1,r,u,v));
}
ll get2(ll id,ll l,ll r,ll u,ll v) {
    if (v < l || u > r) return -inf;
    if (u <= l && v >= r) return st[id][1];
    ll mid=(l+r)>>1;
    return max(get2(2*id,l,mid,u,v),get2(2*id+1,mid+1,r,u,v));
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
    cin>>n>>q;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    build(1,1,n);
    for (ll i=1;i<=q;i++) {
        cin>>l>>r;
        cout<<abs(get1(1,1,n,l,r)-get2(1,1,n,l,r))<<endl;
    }
    return 0;
}
