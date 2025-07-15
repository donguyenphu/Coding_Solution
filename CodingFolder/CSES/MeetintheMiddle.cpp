#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f freopen
#define endl '\n'
using namespace std;
const ll N=44;
ll a[N],n,sum;
vector <ll> vecx,vecy;
void duyetx(ll i,ll x) {
    if (x>sum) {
        return;
    }
    if (i >n/2) {
        vecx.pb(x);
    }
    else {
        duyetx(i+1,x);
        duyetx(i+1,x+a[i]);
    }
}
void duyety(ll i,ll x) {
    if (x>sum) return;
    if (i>n) {
        vecy.pb(x);
    }
    else {
        duyety(i+1,x);
        duyety(i+1,x+a[i]);
    }
}
signed main()
{
    cin.tie()->sync_with_stdio(0);
    cin>>n>>sum;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    duyetx(1,0);
    duyety(n/2+1,0);
    sort(vecy.begin(),vecy.end());
    ll cnt=0;
    for (ll x: vecx) {
        vector <ll> ::iterator it1,it2;
        it1=upper_bound(vecy.begin(),vecy.end(),sum-x);
        it2=lower_bound(vecy.begin(),vecy.end(),sum-x);

        cnt+=(it1-vecy.begin())-(it2-vecy.begin());
    }
    cout<<cnt;
}
