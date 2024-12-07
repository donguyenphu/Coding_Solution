#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+3;
ll a[N],dp[N],maxn;
/// dp[I] là DÃY CON TĂNG DÀI NHẤT KẾT THÚC Ở I
signed main()
{
    /// test sample : 1 2 5 4 6 2
    /// output: 4
    cin.tie()->sync_with_stdio(0);
    ll n;
    cin>>n;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (ll i=1;i<=n;i++) {
        dp[i]=1; /// mặc định là chắc chắn sẽ có dãy con dài nhất có 1 phần tử;
        /// hoặc có thể là trường hợp xấu nhất là không có phần tử nào nhỏ hơn nên độ
        /// dài dãy con tăng dài nhất chỉ có thể là 1
        /// nếu j<i && a[j]<a[i]
        for (ll j=1;j<i;j++) /// xét các phần tử trước đấy xem có thỏa mãn điều kiện không
            if (a[j]<a[i]) {  /// chỉ xét cho các phần tử nhỏ hơn
                 if (dp[j]+1>dp[i]) dp[i]=dp[j]+1;  /// gán
            }
    }
    for (ll i=1;i<=n;i++) {
        if (dp[i]>maxn) {
            maxn=dp[i];
        }
    }
    cout<<maxn;
    /// hướng của bài toán: for từ 1->n (độ dài mảng nhập vào) :
    /// for từ 1 đến phần tử i-1 (để xét các phần tử trước đấy)
    /// nếu dp[j]+1 (sau khi ghép thành dãy con dài nhất kết thúc ở phần tử i) mà lớn hơn dp[i] thì độ dài dãy con dài nhất
    /// của i hiển nhiên sẽ phải ++;
    /// chạy tay dễ hiểu hơn:
    /// dp[1]=1
    /// dp[2]=1+1=2
    /// dp[3]=2+1=3
    /// dp[4]=2+1=3
    /// dp[5]=3+1=4
    /// dp[6]=1+1=2
    /// => MAX=4
}
