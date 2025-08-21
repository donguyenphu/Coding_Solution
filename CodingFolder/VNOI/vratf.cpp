#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, k;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    if (n<=k) cout<<1;
    else {
        if ((n-k)%2) cout<<1;
        else {
            int res = 0;
            queue <int> q;
            q.push((n + k)/2);
            q.push((n - k)/2);
            while (q.size()) {
                int fr = q.front();q.pop();
                if (fr <= k || (fr + k) % 2) res++;
                else {
                    q.push((fr + k)/2);
                    q.push((fr - k)/2);
                }
            }
            cout<<res;
        }
    }
    return 0;
}
