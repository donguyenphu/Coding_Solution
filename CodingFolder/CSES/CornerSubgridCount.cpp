#pragma GCC target ("popcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e3 + 2;
bitset <N> a[N];
int n;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n ; j++)  {
            char x;
            cin>>x;
            a[i][j] = (x - '0');
        }
    }
    int ans = 0;
    for (int i = 1;i <= n; i++) {
        for (int j = i + 1; j <= n ; j++) {
            int tmp = (a[i] & a[j]).count();
            ans += (tmp*(tmp-1))/2;
        }
    }
    cout<<ans;
    return 0;
}
