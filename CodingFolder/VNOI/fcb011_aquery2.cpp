#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define f freopen
using namespace std;
const int N=1e5+4;
pair <ll,ll> a[N];
ll n,k;
ll fi=1,val;
signed main()
{
    cin.tie()->sync_with_stdio(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
 //   if (fopen("AQUERY2.INP","r")) {
 //       f("AQUERY2.INP","r",stdin);
  //      f("AQUERY2.OUT","w",stdout);
 //   }
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++) {
        cin>>a[i].first>>a[i].second;
    }
    sort(a+1,a+n+1);
 /*   for (ll i=1;i<=n;i++) {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    } */
    cin>>k;
    while (k>0) {
        k-=a[fi].second;
        val=a[fi].first;
        fi++;
    }
    cout<<val<<endl;
}
