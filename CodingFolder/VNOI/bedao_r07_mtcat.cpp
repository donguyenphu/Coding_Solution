#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int n, a[N], b[N], child[N][30];
int rmq[N][30];
int mov(int ver, int dis) {
    for (int i = 0; i <= __lg(dis); i++) {
        if ((dis>>i)&1) ver = child[ver][i];
    }
    return ver;
}
void build(int lgg) {
    for (int i = 1; i <= lgg; i++) {
        for (int j = 1; j + (1<<i) - 1 <= n; j++) {
            rmq[j][i] = max(rmq[j][i-1], rmq[j + (1<<(i-1))][i-1]);
        }
    }
}
int get(int l , int r) {
    int k = __lg(r - l + 1);
    return max(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (long long i = 1; i <= n; i++) {
        cin>>a[i];
        rmq[i][0] = a[i];
    }
    build(__lg(n));
    for (long long i = 1; i <= n; i++) {
        cin>>b[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int l = i + 1, r = n;
        int res = 0;
        while (l <= r) {
            int mid = (l + r)>>1;
            if (get(i+1,mid) > a[i]) {
                res = mid;
                r = mid -1;
            }
            else l = mid + 1;
        }
        child[i][0] = res;
    }
    for (int j = 1; j <= 19; j++) {
        for (int i = 1; i <= n; i++) {
            child[i][j] = child[child[i][j-1]][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        int res = mov(i, b[i]);
        cout<<(!res ? -1 : a[res])<<' ';
    }
    return 0;
}
