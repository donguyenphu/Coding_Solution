#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 40;
int n, f[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[0] = 1;
    f[1] = 3;
    for (int i = 2; i <= 30; i++) {
        f[i] = 4 * f[i-1]  - f[i-2];
    }
    while (cin>>n) {
        if (n == -1) return 0;
        else {
            if (n % 2) cout<<0<<endl;
            else cout<<f[n/2]<<endl;
        }
    }
    return 0;
}
