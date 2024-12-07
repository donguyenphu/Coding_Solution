#include <bits/stdc++.h>
#define ll long long
using namespace std;
main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for (ll i=0;i<n;i++) {
        cin>>a[i];
        if (i%2 !=0) sum+=a[i];
    }
    cout<<sum;
}
