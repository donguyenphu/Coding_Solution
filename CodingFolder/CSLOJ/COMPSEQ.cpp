#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second
using namespace std;
const ll mod = 1e9 + 7;
const ll BASE = 311;
const ll inf = 1e17;
const ll N = 3e5 + 4;
ll st[N << 2][3][3];
ll n, q, a[N], b[N];
ll l[N], r[N];
set<ll> s;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p2.inp", "r")) {
        freopen("p2.inp", "r", stdin);
        freopen("p2.out", "w", stdout);
    }
    cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (ll i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            ///     cout<<i<<' ';
            s.insert(i);
        }
    }
    /// cout<<endl;
    for (ll i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        s.erase(l[i]);
        if (r[i] != b[l[i]]) {
            s.insert(l[i]);
        }
        a[l[i]] = r[i];
        /**   for (auto it : s) {
               cout<<it<<' ';
           }
           cout<<endl; */
        if (!s.size()) {
            cout << "N" << endl;
        } else {
            ll idx = *s.begin();
            ///   cout<<idx<<' '<<1111<<' '<<a[idx]<<' '<<b[idx]<<endl;
            cout << (a[idx] > b[idx] ? "Y" : "N") << endl;
        }

        ///  cout<<l[i]<<' '<<r[i]<<endl;
    }
    return 0;
}
