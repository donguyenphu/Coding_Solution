#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
using namespace std;
const ll N=2e5+3;
ll a[N];
ll st[4*N];
void build (ll id, ll l,ll r) {
    if (l==r) {
        st[id]=a[l];
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=st[2*id]+st[2*id+1];
}
ll get (ll id,ll l,ll r,ll u,ll v) {
    if (u>r || v<l) return 0;
    if (u<=l && r<=v) return st[id];
    ll mid=(l+r)/2;
    return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
}
signed main()
{
    cin.tie()->sync_with_stdio(0);
    ll n,q;
    cin>>n>>q;
    for (ll i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    for (ll i=1;i<=q;i++) {
        ll x,y;
        cin>>x>>y;
        cout<<get(1,1,n,x,y)<<endl;
    }
}
