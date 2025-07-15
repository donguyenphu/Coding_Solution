#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll N=2e5+5;
bool ok=false;
ll n,k;
pair<ll,ll> a[N];
main()
{
    cin>>n>>k;
    for (ll i=1;i<=n;i++) {
        cin>>a[i].fi;
        a[i].se=i;
    }
    sort(a+1,a+n+1);
    ll l=1,r=n;
    ll pos1=0,pos2=0;
    while (l<=r && l<n && r >1) {
        if (a[l].fi+a[r].fi==k) {
            pos1=a[l].se;
            pos2=a[r].se;
            ok=true;
            break;
        }
        else if (a[l].fi+a[r].fi<k) {
            l++;
        }
        else r--;
    }
    if (ok) {
        cout<<pos1<<" "<<pos2;
    }
    else cout<<"IMPOSSIBLE";
}
