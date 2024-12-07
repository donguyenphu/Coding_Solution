#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define f freopen
using namespace std;
signed main()
{
    cin.tie()->sync_with_stdio(false);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    ll n,k;
    cin>>n>>k;
    for (ll i=1;i<=n;i++) {
        ll x;
        cin>>x;
    }
    ll ans=(n-1)/(k-1);
    if ((n-1) % (k-1)==0) cout<<ans;
    else cout<<ans+1;
}
