#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e4+3;
ll st[N<<2];
pair <ll,ll> a[N];
ll dp[N];
void up(ll id,ll l,ll r,ll idx,ll vv) {
    if (idx < l || idx > r) return ;
    if (l==r) {
        st[id]=vv;
        return ;
    }
    ll mid=(l+r)>>1;
    up(2*id,l,mid,idx,vv);
    up(2*id+1,mid+1,r,idx,vv);
    st[id]=max(st[2*id],st[2*id+1]);
}
ll get(ll id,ll l,ll r,ll u,ll v) {
    if (v < l || u > r) return 0;
    if (u <= l && v >= r) return st[id];
    ll mid=(l+r)>>1;
    return max(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
    return a.second < b.second;
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
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1,cmp);
    dp[1]=a[1].second-a[1].first;
    up(1,1,n,1,1);
    for (ll i=1;i<=n;i++) {
        ll l=1,r=i;
        ll ans=0;
        dp[i]=a[i].second-a[i].first;
        while (l <= r) {
            ll mid=(l+r)>>1;
            if (a[mid].second <= a[i].first) {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        dp[i]=max(dp[i],get(1,1,n,1,ans)+a[i].second-a[i].first);
        up(1,1,n,i,dp[i]);
    }
    cout<<get(1,1,n,1,n);
    return 0;
}
