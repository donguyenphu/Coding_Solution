#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=6e6+3;
ll a[N];
ll n,q,l,r;
vector <pll> qr[N];
ll ans[N];
ll tt[N][4],bit[N];
vector <ll> cmress={-1};
void up(ll u,ll val) {
    ll idx=u;
    while (idx <= n) {
        bit[idx]+=val;
        idx+=(idx & (-idx));
    }
}
ll get(ll u) {
    ll idx=u,anss=0;
    while (idx > 0) {
        anss+=bit[idx];
        idx-=(idx & (-idx));
    }
    return anss;
}
void qry(ll val,ll idx) {
    if (!tt[val][0]) {
        tt[val][0]=idx;
        up(idx,1);
        return ;
    }
    else {
        tt[val][1]=tt[val][0];
        tt[val][0]=idx;
        up(tt[val][0],1);
        up(tt[val][1],-1);
    }
    return ;
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
    cin>>n;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
        cmress.push_back(a[i]);
    }
    cin>>q;
    for (ll i=1;i<=q;i++) {
        cin>>l>>r;
        qr[r].push_back({l,i});
    }
    sort(cmress.begin(),cmress.end());
    cmress.resize(unique(cmress.begin(),cmress.end())-cmress.begin());
    for (ll i=1;i<=n;i++) a[i]=lower_bound(cmress.begin(),cmress.end(),a[i])-cmress.begin();
   /// for (ll i=1;i<=n;i++) cout<<a[i]<<' ';
   /// cout<<endl;
    for (ll i=1;i<=n;i++) {
        qry(a[i],i);
        for (auto it : qr[i]) {
            ans[it.second]=get(i)-get(it.first-1);
        }
    }
    for (ll i=1;i<=q;i++) cout<<ans[i]<<endl;
    return 0;
}
