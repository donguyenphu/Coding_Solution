#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
using namespace std;
map <ll,ll> mp;
void sieve (ll r) {
    bool prime[r+1];
    memset(prime,true,sizeof(prime));
    for (ll i=2;i*i<=r;i++) {
        if (prime[i]==true) {
            for (ll p=i*i;p<=r;p+=i) prime[p]=false;
        }
    }
    for (ll i=2;i<=r;i++) {
        if (prime[i]) {
       ///     cout<<i<<" ";
            mp[i]++;
        }
    }
}
const int N=1e6+4;
ll a[N],n,maxn=LONG_MIN,minn=LONG_MAX;
ll maxn2=LONG_MIN;
int32_t main() /// để làm được sub3 thì chỉ được for 1 vòng
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    cin>>n;
    sieve(n);
    for (ll i=1;i<=n;i++) cin>>a[i];
    if (n==2) cout<<a[2];
    else {
        for (ll i=2;i<=n;i++) {
            a[i]+=a[i-1];
        }

 /*       for (ll i=1;i<=n;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<endl; */

        for (ll i=2;i<=n;i++) {
            if (mp.find(i) != mp.end()) {
                minn=min(minn,a[i-1]);
                maxn=max(maxn,a[i]-minn);
            }

        }
        cout<<maxn;
    }
///    maximize
}
