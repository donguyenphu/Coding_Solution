#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
using namespace std;

const ll N=1e5+3;
ll a[N];
ll st[4*N];
ll lazy[4*N];

void build (ll id, ll l,ll r) {
    if (l==r) {
        st[id]=0;
        return;
    }
    ll mid=(l+r)/2;

    build(2*id,l,mid);
    build(2*id+1,mid+1,r);

    st[id]=max(st[2*id],st[2*id+1]);
}
void down(ll id,ll l,ll r) {
    ll mid=(l+r)/2;

    st[2*id]+=lazy[id];
    lazy[2*id]+=lazy[id];

    st[2*id+1]+=lazy[id];
    lazy[2*id+1]+=lazy[id];

    lazy[id]=0;
}
void update(ll id,ll l,ll r,ll u,ll v,ll val) {
    if (v < l || u > r) {
        return ;
    }
    if (l >= u && r<= v) {
        st[id]+=val;
     ///   a[l]+=val; /// luu cho mang
        /// không đi xuống các nút con nữa
        lazy[id]+=val;
        return;
    }
    down (id,l,r);
    /// chỉ giao 1 phần với u v

    ll mid=(l+r)/2;

    update(2*id,l,mid,u,v,val);
    update(2*id+1,mid+1,r,u,v,val);

    st[id]=max(st[2*id],st[2*id+1]);
}
ll get (ll id,ll l,ll r,ll u,ll v) {
    if (u>r || v<l) return 0;
    if (u<=l && r<=v) return st[id];
    /// trường hợp chỉ giao 1 phần

    down(id,l,r);
    ll mid=(l+r)/2;
    return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}
signed main()
{
    cin.tie()->sync_with_stdio(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    ll n,q;
    cin>>n>>q;
    build(1,1,n);
    for (ll i=1;i<=q;i++) {
        ll cmd;
        cin>>cmd;
        if (cmd==0) {
            ll u,v,val;
            cin>>u>>v>>val;
            update(1,1,n,u,v,val);
        }
        else if (cmd==1) {
            ll x,y;
            cin>>x>>y;
            cout<<get(1,1,n,x,y)<<endl;
        }
    }
}
