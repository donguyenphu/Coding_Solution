#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long N = 1e4 + 2;
long long a[N], n, m;
long long res = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (long long i = 1; i <= n; i++) {
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    long long l = 1, r = n;
    while (r - l >= 2) {
        long long res2 = -1;
        for (long long i = l + 1; i <= r - 1; i++) {
            if (a[l] + a[r] + a[i] <= m) {
                res2 = i;
                res = max(res, a[l] + a[r] + a[i]);
            }
            else break;
        }
        if (res2 == -1) r--;
        else l++;
    }
    cout<<res;
    return 0;
}
