#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long N = 5e3 + 2;
pair<long long, long long> a[N];
long long n, m;
long long i1 = 0, i2 = 0, i3 = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (long long i = 1; i <= n; i++) {
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 2; i++) {
        if (a[i].first < m) {
            long long target = m - a[i].first;
            int l = i + 1, r = n;
            bool ok = false;
            while (r - l >= 1) {
                if (a[l].first + a[r].first == target) {
                    i1 = a[i].second;
                    i2 = a[l].second;
                    i3 = a[r].second;
                    ok = true;
                    break;
                }
                else if (a[l].first + a[r].first > target) {
                    r--;
                }
                else l++;
            }
            if (ok) break;
        }
        i1 = i2 = i3 = 0;
    }
    if (min({i1, i2, i3}) == 0) {
        cout<<"IMPOSSIBLE";
    }
    else {
        cout<<i1<<' '<<i2<<' '<<i3;
    }
    return 0;
}
