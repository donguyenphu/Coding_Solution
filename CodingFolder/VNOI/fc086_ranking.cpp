#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long N = 3e5 + 2;
long long n, a[N];
vector <long long> cmress = {-1};
map <long long,long long> mp;
long long ma = 0;
long long s = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (long long i = 1; i <= n; i++) {
        cin>>a[i];
        if (!mp[a[i]]) cmress.push_back(a[i]);
        mp[a[i]]++;
    }
    sort(cmress.begin(), cmress.end());
    for (long long i = 1; i <= n; i++) {
        a[i] = lower_bound(cmress.begin(), cmress.end(), a[i]) - cmress.begin();
        ma = max(ma, a[i]);
    }
    for (long long i = 1; i <= n; i++) {
        s += ma - a[i] + 1;
    }
    cout<<s;
    return 0;
}
