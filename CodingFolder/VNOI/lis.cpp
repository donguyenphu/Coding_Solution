#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e4+3;
ll a[N],dp[N],n,maxn;
signed main()
{
    cin.tie()->sync_with_stdio(0);
    cin>>n;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (ll i=1;i<=n;i++) {
        ll j=lower_bound(dp+1,dp+1+maxn,a[i])-dp;
        dp[j]=a[i];
        maxn=max(maxn,j); /// qua trinh xac dinh chuoi con tang co do dai dai nhat
    }
    cout<<maxn<<endl;
}
