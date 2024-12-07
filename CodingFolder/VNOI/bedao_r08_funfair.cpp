#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e6+4;
ll n,x,y,a[N];
ll rel=0,rer=0,res=-inf;
ll pre[N];
ll minpref[N];
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
    cin>>x>>y;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    ll ind=0;
    for (ll i=1;i<=n;i++) {
        ind=i;
        if (a[ind] >= x) {
            ll stat=ind;
            while (ind <=n && a[ind] >= x) {
                ind++;
            }
            ind--;
            pre[stat-1]=0;
            for (ll j=stat;j<=ind;j++) {
                pre[j]=pre[j-1]+a[j];
            }
            ll best=stat-1;
            ll cur=stat-1;
            for (ll j=stat;j<=ind;j++) {
                if (a[j] <= y && a[j] >= x) {
                    while (cur < j) {
                        if (pre[cur] < pre[best]) {
                            best=cur;
                        }
                        cur++;
                    }
                }
                if (cur >= stat && res < pre[j]-pre[best]) {
                    res=pre[j]-pre[best];
                    rel=best+1;
                    rer=j;
                }
            }
        }
        i=ind;
    }
    cout<<res<<endl;
    cout<<rel<<' '<<rer;
    return 0;
}
