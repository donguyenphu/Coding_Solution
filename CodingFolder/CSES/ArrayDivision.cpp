#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 3;

int n, k, a[N];
int r = 1e15;
int l = 0;
int ans = 0;
bool check(int mid) {
    int tmp = 1;
    int sum = 0;
    for (int i = 1; i <= n ; i++) {
        sum += a[i];
        if (sum > mid) {
            tmp++;
            sum =a[i];
        }
    }
    return tmp <= k;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i = 1; i <= n ; i++) {
        cin>>a[i];
        l = max(l, a[i]);
    }
    while (l <= r) {
        int mid = (l + r)>>1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout<<ans;
}
