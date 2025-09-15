#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 2;
int n, a[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout<<(a[i] ^ a[j])<<' ';
        }
        cout<<endl;
    }
    return 0;
}
