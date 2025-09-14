#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
int d[N][4], n, a[N], st[N*4];
long long s = 0;
void up(int id, int l, int r, int idx, int val) {
    if (idx < l || idx > r) return ;
    if (l == r) {
        st[id] = val;
        return ;
    }
    int mid = (l + r)>>1;
    up(2*id,l,mid,idx,val);
    up(2*id+1,mid+1,r,idx,val);
    st[id] = st[2*id] + st[2*id+1];
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r)>>1;
    return get(2*id,l,mid,u,v)+get(2*id+1,mid+1,r,u,v);
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
    up(1,1,n,1,1);
    d[a[1]][0] = 1;
    for (int i = 2; i <= n; i++) {
        if (!d[a[i]][0]) {
            d[a[i]][0] = i;
            up(1,1,n,i,1);
            s+=get(1,1,n,1,i)-1;
        }
        else {
            if (!d[a[i]][1]) {
                d[a[i]][1] = i;
                up(1,1,n,i,1);
                up(1,1,n,d[a[i]][0],0);
            }
            else {
                d[a[i]][0] = d[a[i]][1];
                d[a[i]][1] = i;
                up(1,1,n,d[a[i]][0],0);
                up(1,1,n,d[a[i]][1],1);
            }
            s+=get(1,1,n,d[a[i]][0]+1,d[a[i]][1])-1;
        }
    }
    cout<<s;
    return 0;
}
