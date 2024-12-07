#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=3e3+2;
ll a[N][N],pre[N][N],cf[N][N];
/// h w le
ll n,m,r,c;
ll gett(ll i,ll j,ll x,ll y) {
    return pre[x][y]-pre[x][j-1]-pre[i-1][y]+pre[i-1][j-1];
}
bool ck(ll mid) {
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) pre[i][j]=cf[i][j]=0;
    }
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) cf[i][j]=(a[i][j] >= mid ? 1 : -1);
    }
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++)
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+cf[i][j];
    }
    for (ll i=1;i<=n-r+1;i++) {
        for (ll j=1;j<=m-c+1;j++) {
            if (gett(i,j,i+r-1,j+c-1) > 0) return true;
        }
    }
    return false;
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
    cin>>n>>m>>r>>c;
   /// cout<<n<<' '<<m<<' '<<r<<' '<<c<<endl;
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            cin>>a[i][j];
        }
    }
    /// sub1
    ll ans=-1,l1=1,r1=n*m;
    while (l1 <= r1) {
        ll mid=(l1+r1)>>1;
        if (ck(mid)) {
            ans=mid;
            l1=mid+1;
        }
        else r1=mid-1;
    }
    cout<<ans;
    return 0;
}
