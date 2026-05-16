#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
int store[N], n;
long long result = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>store[i];
    }
    for (int i = 2; i <= n; i++) {
        if (store[i] < store[i-1]) {
            result += store[i-1] - store[i];
            store[i] = store[i-1];
        }
    }

    cout<<result;
    return 0;
}
