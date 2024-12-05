#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int trailing_Zeroes(ll n) {
    int number = 0;
    while (n > 0) {
        number += n / 5;
        n /= 5;
    }
    return number;
}
int main()
{
    cin.tie()->sync_with_stdio(0);
    ll t;
    cin>>t;
    while (t--) {
        ll n;
        cin>>n;
        cout<<trailing_Zeroes(n)<<endl;
    }
}
