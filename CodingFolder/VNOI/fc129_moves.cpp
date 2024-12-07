#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll N=1e3+3;
ll a[N];
signed main() {
    cin.tie()->sync_with_stdio(false);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
  /*  if (fopen("moves.inp","r")) {
        f("moves.inp","r",stdin);
        f("moves.out","w",stdout);
    } */
    ll t;
    cin>>t;
    while (t--) {
        ll s=0;
        ll n,d;
        cin>>n>>d;
        for (ll i=1;i<=n;i++) {
            cin>>a[i];
            s+=a[i];
        }
        for (ll i=1;i<=n;i+=2) {
            s-=d;
        }
        if (s>0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
