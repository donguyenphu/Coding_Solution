#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
bool notPrime[N];
int t, n;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    notPrime[1] = notPrime[0] = true;
    for (int i = 2; i * i <= 10000000; i++) {
        if (!notPrime[i]) {
            for (int j = i * i; j <= 10000000; j+=i) {
                notPrime[j] = true;
            }
        }
    }
    cin>>t;
    while (t--) {
        cin>>n;
        cout<<(notPrime[n] ? "NO" : "YES")<<endl;
    }
}
