#include <bits/stdc++.h>
using namespace std;

long long t, y, x;
long long result = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--) {
        cin>>y>>x;

        if (x==y) result = x * x - (x - 1);
        else if (y > x) {
            if (y % 2 == 0) result = y * y - (x - 1);
            else result = (y - 1) * (y - 1) + x;
        }
        else if (y < x) {
            if (x % 2 == 0) result = (x - 1) * (x - 1) + y;
            else result = x * x - (y - 1);
        }

        cout<<result<<endl;
    }

    return 0;
}
