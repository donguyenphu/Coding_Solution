#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll a[N];
int main()
{
    cin.tie()->sync_with_stdio(0);
    ll n;
    cin>>n;
    ll sum=0,sum2=0,minn=1e9;
    for (ll i=0;i<n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    for (ll i=0;i<n-1;i++) {
        sum2+=a[i];
        minn=min(minn,abs((sum-sum2)-sum2));
    }
    cout<<minn;
}
