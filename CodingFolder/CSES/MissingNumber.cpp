#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
using namespace std;
map <ll,ll> m;
signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++) {
        ll x;
        cin>>x;
        m[x]++;
    }
    for (ll i=1;i<=n;i++) {
        if (m.find(i) == m.end()) cout<<i;
    }
}
