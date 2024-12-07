#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
using namespace std;

const int N=25;
const int F=45;
ll a[N][N][F] ,dp[N][N][F];
ll x,b,c;
map <ll,ll> mp;
ll maxn=LONG_MIN,minn=LONG_MAX;
int32_t main() /// để làm được sub3 thì chỉ được for 1 vòng
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    cin>>x>>b>>c;
    for (ll i=1;i<=x;i++) {
        for (ll j=1;j<=b;j++) {
            for (ll k=1;k<=c;k++) {
                a[i][j][k]=i+j+k;
                mp[a[i][j][k]]++;
            }
        }
    }
    map <ll,ll> ::iterator it;
    for (it=mp.begin();it != mp.end();it++) {
        maxn=max(maxn,it->second);
    }
    for (it=mp.begin();it !=mp.end();it++) {
        if (it->second==maxn) {
            minn=min(minn,it->first);
        }
    }
    cout<<minn;
}
