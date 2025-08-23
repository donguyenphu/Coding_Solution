#include <bits/stdc++.h>
using namespace std;
signed main()
{
    for (int i = 1; i <= 2; i++) {
        long long a, b, c;
        cin>>a>>b>>c;
        if (a + b + c - max({a,b,c}) == max({a,b,c})) {
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;
    }
    return 0;
}
