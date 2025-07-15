#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
using namespace std;
signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    ll n;
    cin>>n;
    cout<<n<<" ";
    while (n != 1) {
        if (n%2==0) n/=2;
        else n=n*3+1;
        cout<<n<<" ";
    }
}
