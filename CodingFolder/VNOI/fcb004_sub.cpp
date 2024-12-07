#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+4;
ll n,a[N],t;
ll pre[N],mi[N];
ll ma=-inf,sum=0;
bool choose=false;
struct dd {
    ll sum,pre,suf,best;
};
dd st[N<<2];
dd j(dd l,dd r) {
    dd res;
    res.sum=l.sum+r.sum;
    res.pre=max(l.pre,l.sum+r.pre);
    res.suf=max(r.suf,r.sum+l.suf);
    res.best=max({max(l.best,r.best),l.suf+r.pre,l.sum+r.pre,r.sum+l.suf});
    return res;
}
void build(ll id,ll l,ll r) {
    if (l==r) {
        st[id].sum=st[id].pre=st[id].suf=st[id].best=a[l];
        return ;
    }
    ll mid=(l+r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=j(st[2*id],st[2*id+1]);
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
    cin>>t;
    while (t--) {
        cin>>n;
        mi[0]=inf;
        for (ll i=1;i<=n;i++) {
            cin>>a[i];
            ma=max(ma,a[i]);
            if (a[i] >= 0) {
                choose=true;
                sum+=a[i];
            }
        }
        build(1,1,n);
        cout<<(choose ? sum : ma)<<' ';
        cout<<st[1].best<<endl;
        for (ll i=0;i<=n;i++) pre[i]=mi[i]=a[i]=0;
        for (ll i=0;i<=4*n;i++) st[i].sum=st[i].pre=st[i].suf=st[i].best=0;
        choose=false;
        ma=-inf;
        sum=0;
    }
    return 0;
}
