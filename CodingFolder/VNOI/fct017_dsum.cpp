#include <bits/stdc++.h>
using namespace std;
string s;
long long sum = 0;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for (int i = 0 ; i < s.size(); i++) {
        sum += s[i] - '0';
    }
    cout<<sum;
    return 0;
}
