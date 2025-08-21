#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e5+2;
int n;
int tmp1 = 0, tmp2 = 0;
string a[N];
vector <string> res;
string s;
string tmp = "";
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
        if (a[i][0] == '0') continue;
        else if (a[i][0] == '-') tmp1++;
        else tmp2++;
    }
    cout<<tmp1<<' '<<tmp2;
    return 0;
}
