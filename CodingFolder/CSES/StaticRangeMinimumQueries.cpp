#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f freopen
#define endl '\n'
using namespace std;
const ll N=2e5+2;
ll a[N],st[4*N];
ll n,q;
const ll INF=1e9+7;
void build (ll id,ll l,ll r) {
    if (l==r) {
        st[id]=a[l];
        return ;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=min(st[2*id],st[2*id+1]);
}
ll get(ll id,ll l,ll r,ll u,ll v) {
    if (v < l || u > r) return INF;
    if ( u <=l && r <=v) {
        return st[id];
    }
    ll mid=(l+r)/2;
    ll t1=get(2*id,l,mid,u,v);
    ll t2=get(2*id+1,mid+1,r,u,v);
    return min(t1,t2);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    build(1,1,n);
    for (ll i=1;i<=q;i++) {
        ll a,b;
        cin>>a>>b;
        cout<<get(1,1,n,a,b)<<endl;
    }
}
