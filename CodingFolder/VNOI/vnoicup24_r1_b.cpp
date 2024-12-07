#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const ll N = 2e5+8;
ll n, a[N], b[N];

signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    cout.tie(0);
    ll tc;
    cin >> tc;
    while (tc--){
        cin >> n;
        for (ll i = 1; i <= n; ++i) cin >> a[i];
        for (ll i = 1; i <= n; ++i) cin >> b[i];

        string ans = "YES";
        for (ll i = 1; i < n; ++i){
            if (a[i] >= b[i]){
                ll amt = (a[i] - b[i]) / 2;
                a[i] -= 2 * amt;
                a[i + 1] += amt;
            }
            else{
                ll diff = b[i] - a[i];
                a[i] += diff;
                a[i + 1] -= ((diff + 1) / 2);
            }
        }

        if (a[n] < b[n]) ans = "NO";
        cout << ans << endl;
    }
    return 0;
}
