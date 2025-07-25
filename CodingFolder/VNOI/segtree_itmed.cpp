#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long lim = -2e15;
const int N = 1e5 + 3;
int a[N], n, st[N<<2], q, t, l, r, val, laz[N<<2], k;
int dp[N];
void init(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return ;
    }
    int mid = (l + r)>>1;
    init(2*id, l, mid);
    init(2*id + 1, mid + 1, r);
    st[id] = max(st[2*id], st[2*id + 1]);
}
void down(int id, int l, int r) {
    st[2*id] += laz[id];
    st[2*id + 1] += laz[id];
    laz[2*id] += laz[id];
    laz[2*id + 1] += laz[id];
    laz[id] = 0;
    return ;
}
void uplaz(int id, int l, int r, int u, int v, int val) {
    if (v < l || u > r) {
        return ;
    }
    if (u <= l && r <= v) {
        st[id] += val;
        laz[id] += val;
        return ;
    }
    down(id, l, r);
    int mid = (l + r) >> 1;
    uplaz(2 * id, l, mid, u, v, val);
    uplaz(2 * id + 1, mid + 1, r, u, v, val);
    st[id] = max(st[2*id], st[2*id + 1]);
}
void upone(int id, int l, int r, int idx, int val) {
    if (idx < l || idx > r) {
        return ;
    }
    if (l == r) {
        st[id] = val;
        return ;
    }
    int mid = (l + r)>>1;
    upone(2 * id, l,  mid, idx, val);
    upone(2 * id + 1, mid + 1, r, idx, val);
    st[id] = max(st[2*id], st[2*id+1]);
}
long long get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return lim;
    if (u <= l && v >= r) return st[id];
 ///   down(id, l, r);
    int mid = (l + r)>>1;
    return max(get(2*id, l, mid, u, v), get(2*id + 1, mid + 1, r, u, v));
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i <= k) {
            dp[i] = get(1, 1, n, 1, i) + a[i];
            upone(1, 1, n, i, dp[i]);
        }
        else {
            dp[i] = get(1, 1, n, i - k, i) + a[i];
            upone(1, 1, n, i, dp[i]);
        }
    }
    long long maxn = lim;
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, get(1,1,n,i,i));
    }
    cout<< max(maxn, 0LL);
    return 0;
}
