#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
using namespace std;
const ll N=3e4+3;
ll a[N],st[4*N];

signed main()
{
    cin.tie()->sync_with_stdio(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    ll q;
    cin>>q;
    while (q--) {
  /*      build(1,1,n);
        ll i,j,val;
        cin>>i>>j>>val;
        for (ll k=i;k<=j;k++) {
            update(1,1,n,k,val);
        }
        cout<<get(1,1,n,i,j)<<endl; */
        ll cnt=0;
        ll i,j,val;
        cin>>i>>j>>val;
        for (ll k=i;k<=j;k++) {
            if (a[k]>val) cnt++;
        }
        cout<<cnt<<endl;
    }
}
/*
void build (ll id,ll l,ll r) {
    if (l==r) {
        st[id]=0;
        return;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=st[2*id]+st[2*id+1];
}
ll get(ll id,ll l,ll r,ll u,ll v) {
    if (u > r || v < l) return 0;
    if (u <=l && v>=r) return st[id];

    ll mid=(l+r)/2;
    return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
}

void update(ll id,ll l,ll r,ll pos,ll val) {
    if (pos < l || pos >r) return;
    if (l==r) {
        if (a[pos] > val) {
            st[id]++;
            return;
        }
    }
    ll mid=(l+r)/2;
    update(2*id,l,mid,pos,val);
    update(2*id,mid+1,r,pos,val);
    st[id]=st[2*id]+st[2*id+1];
}
 */
