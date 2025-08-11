#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e4 + 2;
long long a[N], n;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        priority_queue <int, vector<int>, greater<int>> pq;
        long long s = 0;
        cin>>n;
        for (int i = 1; i <= n; i++) {
            cin>>a[i];
            pq.push(a[i]);
        }
        while (pq.size() >= 2) {
            int u = pq.top();pq.pop();
            int v = pq.top();pq.pop();
            s += u + v;
            pq.push(u + v);
        }
        cout<<s<<endl;
    }
    return 0;
}
