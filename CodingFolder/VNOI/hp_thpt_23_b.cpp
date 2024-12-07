#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define pb push_back
#define endl '\n'
using namespace std;
const ll N=1e3+1;
const ll In=1e4+3;
ll a[N],st[4*N];
ll n,q;
ll cnt[In];
void sang(ll n) {
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
        if (prime[i]) cnt[i]++;
    }
}
bool check(ll n) {
    if  (n<=1) return false;
    for (ll i=2;i*i<=n;i++) {
        if (n%i==0) return false;
    }
    return true;
}
void build(ll id,ll l,ll r) {
    if (l==r) {
        st[id]=a[l];
        return ;
    }
    ll mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id]=st[2*id]+st[2*id+1];
}
ll get (ll id,ll l,ll r,ll u,ll v) {
    if (u>r || v<l) return 0;
    if (u<=l && r<=v) return st[id];
    ll mid=(l+r)/2;
    ll t1=get(2*id,l,mid,u,v);
    ll t2=get(2*id+1,mid+1,r,u,v);
    return t1+t2;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll cnt=0;
    string s;
    cin>>s;
    for (ll i=0;i<s.size();i++) {
        if (isdigit(s[i])) cnt++;
    }
    cout<<cnt;
}
