#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 1e5 + 3;
int n, a[N];
stack <int> st;
int cnt = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (st.size() && st.top() > a[i]) {
            st.pop();
        }
        if ((st.size() && st.top() == a[i]) || (a[i] == 0)) {
            continue;
        }
        st.push(a[i]);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
