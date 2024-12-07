#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll BASE=33;
const ll N=1e6+4;
ll poww[N],has[N];
ll has2[N];
string a,b;
void pre() {
    poww[0]=1;
    for (ll i=1;i<=1000002;i++) {
        poww[i]=(poww[i-1]*BASE)%mod;
    }
}
void build(ll has[],string s) {
    for (ll i=1;i<s.size();i++) {
        has[i]=(has[i-1]*BASE+s[i]-'a')%mod;
    }
}
ll get1(ll l,ll r) {
    return (has[r]-has[l-1]*poww[r-l+1]+mod*mod)%mod;
}
ll get2(ll l,ll r) {
    return (has2[r]-has2[l-1]*poww[r-l+1]+mod*mod)%mod;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    pre();
    cin>>a>>b;
    ll n=a.size(),m=b.size();
    a=" "+a;
    b=" "+b;
    build(has,a);
    build(has2,b);
    if (n >= m) {
        for (ll i=1;i+m-1<=n;i++) {
            if (get1(i,i+m-1)==get2(1,m)) {
                cout<<i<<' ';
            }
        }
    }
    return 0;
}
