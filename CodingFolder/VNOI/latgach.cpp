#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define f freopen
using namespace std;
const ll N=104;
string dp[N];
ll n;
string add (string a,string b) {
    int x=a.size()-b.size();
    x=abs(x); /// convert to positive
    string c="";
    for (ll i=0;i<x;i++) {
        c+="0";
    }
    if (a.size() < b.size()) a=c+a;
    else b=c+b;
    ll n=a.size();
    string t="";
    ll r=0;
    for (ll i=n-1;i>=0;i--) {   /// for ngược
        ll s=a[i]+b[i]-'0'-'0'+r;
        if (s>9) r=1,s-=10;
        else r=0;
        t+=(char)(s+'0');
    }
    if (r) t+="1";
    reverse(t.begin(),t.end());
    return t;
}
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
    dp[1]="1";
    dp[2]="2";
    for (ll i=3;i<=100;i++) {
        dp[i]=add(dp[i-1],dp[i-2]);
    }
    while (t--) {
        cin>>n;
        cout<<dp[n]<<endl;
    }
}
