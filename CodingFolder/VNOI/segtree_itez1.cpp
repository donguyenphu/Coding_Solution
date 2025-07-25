#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long lim = -2e9;
const int N = 1e5 + 3;
int a[N], n, st[N<<2], q, t, l, r;
void init (int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return ;
    }
    int mid = (l + r)>>1;
    init(2 * id, l, mid);
    init(2 * id + 1, mid + 1, r);
    st[id] = max(st[2*id], st[2*id + 1]);
}
void up (int id, int l, int r, int idx, int val) {
    if (idx < l || idx > r) {
        return ;
    }
    if (l == r) {
        st[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    up(2 * id, l, mid, idx, val);
    up(2 * id + 1, mid + 1, r, idx, val);
    st[id] = max(st[2*id], st[2*id + 1]);
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return lim;
    if (u <= l && v >= r) return st[id];
    int mid = (l + r)>>1;
    return max(get(2*id, l, mid, u, v), get(2*id + 1, mid + 1, r, u, v));
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    init(1, 1, n);
    cin>>q;
    for (int i = 1; i <= q; i++) {
        cin>>t>>l>>r;
        if (t == 1) {
            up(1, 1, n, l, r);
        }
        else {
            cout<<get(1, 1, n, l, r)<<endl;
        }
    }
    return 0;
}
