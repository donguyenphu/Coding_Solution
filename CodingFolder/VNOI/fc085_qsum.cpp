#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5 + 4;
long long n, q, a[N], l , r, pre[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        pre[i] = a[i] + pre[i-1];
    }
    for (int i = 1; i <= q; i++) {
        cin>>l>>r;
        cout<<pre[r] - pre[l - 1]<<endl;
    }
}
