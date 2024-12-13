#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=3e5+4;
ll st[N<<2][4];
pll a[N],b[N];
ll n;
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
        cin>>a[i]>>b[i];
        a[i].first=i,b[i].first=i;
    }
    return 0;
}
