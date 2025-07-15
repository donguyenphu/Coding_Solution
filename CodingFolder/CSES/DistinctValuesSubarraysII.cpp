#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 3;
int ma = 0;
int n,k,a[N];
vector <int> rr = {-1};
vector <int> ind[N];
int bit[N];
int amount = 0;
int get(int idx) {
    int ans = 0;
    while (idx > 0) {
        ans +=bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
void up(int u,int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i = 1;i <= n ; i++) {
        cin>>a[i];
        rr.push_back(a[i]);
    }
    sort(rr.begin(),rr.end());
    rr.resize(unique(rr.begin(),rr.end()) - rr.begin());
    for (int i = 1; i <= n; i++) a[i]=lower_bound(rr.begin(),rr.end(), a[i]) - rr.begin();
    for (int i = 1; i <= n ; i++) {
        if (ind[a[i]].empty()) {
            up(i, 1);
            ind[a[i]].push_back(i);
        }
        else {
            int siz = ind[a[i]].size();
            int last = ind[a[i]][siz-1];
            up(last, -1);
            up(i, 1);
            ind[a[i]].push_back(i);
        }
        int ans = -1;
        int l = 1, r = i;
        while (l <= r) {
            int mid = (l + r)>>1;
            if (get(i) - get(mid - 1) <= k) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        amount += i - ans + 1;

    }
    cout<<amount;
    return 0;
}
