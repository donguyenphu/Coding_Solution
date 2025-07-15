#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define f freopen
#define pb push_back
using namespace std;
const ll N=1e5+3;
bool visited[N];
vector <ll> lack;
vector <ll> adj[N];
map <ll,ll> mp;
void dfs(ll i) {
    visited[i]=true;
    for (auto it: adj[i]) {
        if (!visited[it]) {
            dfs(it);
        }
    }
}
ll cc(ll n) {
    ll cnt=0;
    for (ll i=1;i<=n;i++) {
        if (!visited[i]) {
            lack.pb(i);
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for (ll i=1;i<=m;i++) {
        ll a,b;
        cin>>a>>b;
        mp[a]++;
        mp[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll res=cc(n);
    if (mp.size()== n) { /// không thiếu
        ll ans=(res==1) ? 0 : 1;
        cout<<ans<<endl;
        if (ans != 0) {
            for (ll i=0;i<lack.size()-1;i++) {
                cout<<lack[i]<<" "<<lack[i+1]<<endl;
            }
        }
    }
    else {  /// node thiếu
        cout<<lack.size()-1<<endl;
        for (ll i=0;i<lack.size()-1;i++) {
            cout<<lack[i]<<" "<<lack[i+1]<<endl;
        }
    }
}
