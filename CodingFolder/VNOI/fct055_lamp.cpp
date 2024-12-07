#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    bool a[n+1];
    memset(a,false,sizeof(a));
    for (ll i=1;i<=q;i++) {
        ll x,y;
        cin>>x>>y;
        for (ll j=x;j<=y;j++) {
            if (a[j]==true) a[j]=false;
            else a[j]=true;
        }
    }
    for (ll i=1;i<=n;i++) {
        if (a[i]==true) cout<<1<<" ";
        else cout<<0<<" ";
    }
}
