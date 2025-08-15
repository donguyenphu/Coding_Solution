#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e5 + 2;
map <int, int> mp;
set<int, greater<int>> s;
int n, a[N];
int tmp = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        s.insert(a[i]);
        mp[a[i]]++;
    }
    while (*s.begin() - *s.rbegin() > 1) {
        int ma = *s.begin();
        int mi = *s.rbegin();
        int minP = min(mp[ma], mp[mi]);
        tmp += minP;
        mp[ma]-= minP;
        mp[mi]-= minP;
        if (!mp[ma]) s.erase(ma);
        if (!mp[mi]) s.erase(mi);
        ma--;
        mi++;
        mp[ma] += minP;
        mp[mi] += minP;
        s.insert(ma);
        s.insert(mi);
    }
    cout<<tmp;
    return 0;
}
