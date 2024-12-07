#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
using namespace std;
const ll F=2e5+4;
ll a[F],cnt[F];
ll n;
map <ll,ll> cnt1;
map <ll,ll> cnt2;
ll res=0;
/// IDGAF about counting
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    cin>>n;
    if (n<7) cout<<0<<endl;
    else {
        for (ll i=1;i<=n;i++) {
            cin>>a[i];
        }
        for (ll i=1;i<=n;i++) {
            if (i>=7) {cnt[a[i-6]%23]++;}
            res+=cnt[a[i]%23];
        }
        cout<<res;
   /*     for (ll i=1;i<=n-6;i++) {
            cnt1[a[i]%23]++;
        }
        for (ll i=7;i<=n;i++) {
            cnt2[a[i]%23]++;
        }
    /*    for (ll i=0;i<=22;i++) {
            if (cnt1.find(i)==cnt1.end()) cnt1[i]=0;
            if (cnt2.find(i) == cnt2.end()) cnt2[i]=0;
        } */
    /*    ll res=0;
   ///     map <ll,ll> ::iterator it;
        for (ll i=0;i<=22;i++) {
         ///   cout<<cnt1[i]<<" "<<cnt2[i]<<endl;
            res+=cnt1[i]*cnt2[i];
        }
        cout<<res; */
    }
}
