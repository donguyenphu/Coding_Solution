#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 3;
int store[N], n;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (n <= 4) {
        if (n == 1) cout<<1;
        else if (n == 4) cout<<2<<' '<<4<<' '<<1<<' '<<3;
        else cout<<"NO SOLUTION";
        return 0;
    }
    for (int i = 1; i <= n; i += 2) cout<<i<<' ';
    for (int i = 2; i <= n; i += 2) cout<<i<<' ';
    return 0;
}
