#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define f freopen
#define pll pair<ll,ll>
using namespace std;
const ll N=1e5+5;
vector<ll> adj[N];
ll rnk[N];
ll pa[N];
ll siz[N];
ll n,m,a,b;
ll maxn=LONG_MIN;
ll fi=0;
void make() {
    for (ll i=1;i<=n;i++) {
        pa[i]=i;
        siz[i]=1;
        rnk[i]=0;
    }
}
ll fin(ll i) {
    return (i==pa[i]) ? i : pa[i]=fin(pa[i]);
}
void uni(ll a,ll b) {
    a=fin(a);
    b=fin(b);
    if (a != b) {
        fi--;
        pa[b]=a;
        siz[a]+=siz[b];
    }
}
void it() {
    for (ll i=1;i<=n;i++) {
        cout<<i<<" "<<siz[i]<<" "<<rnk[i]<<" "<<pa[i]<<endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    make();
    fi=n;
    for (ll i=1;i<=m;++i) {
        cin>>a>>b;
        uni(a,b);
        maxn=max(maxn,siz[fin(a)]);
        cout<<fi<<" "<<maxn<<endl;
    }
}
