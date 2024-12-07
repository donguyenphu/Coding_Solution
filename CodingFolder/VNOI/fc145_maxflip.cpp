#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll N=1e5+4;
ll a[N];
ll n,m,k,q;
priority_queue <ll> hmx;
ll sum=0;
signed main()
{
    cin.tie()->sync_with_stdio(false);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
  /*  if (fopen("MAXFLIP.inp","r")) {
        freopen("MAXFLIP.INP","r",stdin);
        freopen("MAXFLIP.OUT","w",stdout);
    } */
 /*   cin>>n>>m>>k>>q;
    for (ll i=1;i<=n;i++) cin>>a[i]; */
    cin>>n;
    ll cntp=0;
    ll cntn=0;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
        if (a[i]==1) cntp++;
        else cntn++;
    }
///    cout<<sum<<endl;
    if (cntn==0) cout<<sum+4;
    else if (cntp==0) cout<<sum-4;
    else {   /// co am co duong
        for (ll i=2;i<=n-1;i++) {
            if (a[i]==-1) {
                if (a[i-1]==-1 || a[i+1]==-1) {   ///2 -1 gần kề
                    cout<<sum+4;
                    exit(0);
                }
            }
        }
        cout<<sum; /// xen kẽ;
    }
}
