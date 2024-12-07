#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define pb push_back
#define endl '\n'
using namespace std;
const ll N=1e6+2;
ll a[N];
ll n,k;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    ll t;
    cin>>t;
    while (t--) {
        map <ll,ll> mp;
        cin>>n>>k;
        for (ll i=1;i<=n;i++) {
            cin>>a[i];
        }
        bool ok=false;
        for (ll i=1;i<=n;i++) {
            if (a[i] < k) {
                if (a[i] % 2 ==0) {

                    if (mp.find(k-a[i]) != mp.end() && mp[k-a[i]]==3) {
                        ok=true;
                        break;
                    }
                    mp[a[i]]=4;  /// even
                }
                else {
                    if (mp.find(k-a[i]) != mp.end() && mp[k-a[i]]==4) {
                        ok=true;
                        break;
                    }
                    mp[a[i]]=3; /// odd
                }
            }
        }
        if (ok) cout<<1;
        else if (!ok) cout<<0;
    }
}
