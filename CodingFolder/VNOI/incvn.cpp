#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 5e6;
int n, k, a[10002];
int dp[10002][52];
vector <int> cr = {-1};
map <int,int> mp;
int st[40002][52];
int get(int id, int l, int r, int u, int v, int num) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return st[id][num];
    int mid = (l + r)>>1;
    return get(2*id,l,mid,u,v,num) + get(2*id+1,mid+1,r,u,v,num);
}
void up(int id, int l, int r, int idx, int val, int num) {
    if (idx < l || idx > r) return ;
    if (l==r) {
        if (num==1) st[id][num] = val;
        else st[id][num] = (st[id][num] + val)%mod;
        return ;
    }
    int mid = (l+r)>>1;
    up(2*id,l,mid,idx,val,num);
    up(2*id+1,mid+1,r,idx,val,num);
    st[id][num] = st[2*id][num] + st[2*id+1][num];
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        if (!mp[a[i]]) cr.push_back(a[i]);
        mp[a[i]]++;
    }
    sort(cr.begin(), cr.end());
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(cr.begin(), cr.end(), a[i]) - cr.begin();
    }
    dp[a[1]][1] = (dp[a[1]][1] + 1)%mod;
    up(1,1,n,a[1],dp[a[1]][1],1);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(a[i], k); j++) {
            if (j == 1) {
                dp[a[i]][1] = (dp[a[i]][1] + 1) % mod;
                up(1,1,n,a[i],dp[a[i]][1],1);
            }
            else {
                dp[a[i]][j] = get(1,1,n,1,a[i]-1,j-1) % mod;
                up(1,1,n,a[i],dp[a[i]][j],j);
            }
        }
    }
    cout<<get(1,1,n,1,n,k)%mod;
    return 0;
}
