#include <bits/stdc++.h>
#define ll long long
using namespace std;
map <ll,ll> mp;
const ll N=2e5+3;
ll a[N];
signed main()
{
    cin.tie()->sync_with_stdio(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++) cin>>a[i];
    ll cnt=0,sum=0;
    for (ll i=1;i<=n;i++) {
        sum+=a[i];
        if (sum==0) cnt++;
        cnt+=mp[sum];
        mp[sum]++;
    }
    cout<<cnt;
}
