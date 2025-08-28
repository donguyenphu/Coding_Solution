#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long x,k;
    cin>>x>>k;
    cout<<k/(gcd(x,k));
    return 0;
}
