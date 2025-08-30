#include <bits/stdc++.h>
using namespace std;
const long long lim = 2e9;
const long long N = 1e5 + 2;
long long n, a[N], st[N * 4], tmp = 0;
void build(long long id, long long l, long long r) {
    if (l == r)  {
        st[id] = a[l];
        return ;
    }
    long long mid = (l + r)>>1;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    st[id] = min(st[2*id], st[2*id+1]);
}
void up(long long id, long long l, long long r, long long idx, long long val) {
    if (idx < l || idx > r) return ;
    if (l == r) {
        st[id] = val;
        return ;
    }
    long long mid = (l + r)>>1;
    up(2*id,l,mid,idx,val);
    up(2*id+1,mid+1,r,idx,val);
    st[id] = min(st[2*id], st[2*id+1]);
}
long long get(long long id, long long l, long long r, long long u, long long v) {
    if (v < l || u > r) return lim;
    if (u <= l && v >= r) return st[id];
    long long mid = (l + r)>>1;
    return min(get(2*id,l,mid,u,v),get(2*id+1,mid+1,r,u,v));
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (long long i = 1; i <= n; i++) {
        cin>>a[i];
    }
    build(1,1,n);
    long long val = get(1,1,n,1,n);
    while (val < lim) {
        long long val = get(1,1,n,1,n);
        if (val == lim) break;
        long long l = 1, r = n;
        long long ans = -1;
        while (l <= r) {
            long long mid = (l + r)>>1;
            if (get(1,1,n,1,mid) <= val) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        up(1,1,n,ans,lim);
        if (ans > 1) up(1,1,n,ans-1,lim);
        if (ans < n) up(1,1,n,ans+1,lim);
        tmp++;
    }
    cout<<tmp;
    return 0;
}
