#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+1;
const ll REM=1e2+1;
const ll mod=1e9+7;
ll dp[N][REM][2],dig[N];
string s;
ll d;
ll bac(ll pos,ll rem,bool lower) {
    if (!pos) {
        return (!rem);
    }
    ll &res=dp[pos][rem][lower];
    if (res != -1) {
        return res;
    }
    res=0;
    ll lim=(lower ? 9 : dig[pos]);
    for (ll j=0;j<=lim;j++) {
        bool ok2=(lower || j < lim);
        res=(res+bac(pos-1,(rem+j)%d,ok2))%mod;
    }
    return res;
}
ll calc(string s,ll n) {
    memset(dp,-1,sizeof(dp));
  ///  memset(dig,0,sizeof(dig));
    ll tm=0;
    string ff=s;
    for (ll i=n;i>=1;i--) {
        dig[++tm]=s[i]-'0';
    }
    return bac(tm,0,false);
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
    #define NAME "num3"
    if (fopen("num3.inp","r")) {
        freopen("num3.inp","r",stdin);
        freopen("num3.out","w",stdout);
    }
    cin>>s;
    cin>>d;
    ll n=s.size();
    s=" "+s;
    cout<<(calc(s,n) -1 + mod) %mod<<'\n';
    return 0;
}
