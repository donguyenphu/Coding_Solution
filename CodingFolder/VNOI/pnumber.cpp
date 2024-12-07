#include <bits/stdc++.h>
#define ll long long
using namespace std;
void sang(ll l,ll n)
{
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for (ll i=2;i*i<=n;i++) {
        if (prime[i]==true) {
            for (ll p=i*i;p<=n;p+=i) {
                prime[p]=false;
            }
        }
    }
    for (ll i=2;i<=n;i++) {
        if (prime[i] && i>=l) {
            cout<<i<<endl;
        }
    }
}
int main()
{
    cin.tie()->sync_with_stdio(0);
    ll l,n;
    cin>>l>>n;
    sang(l,n);
}
