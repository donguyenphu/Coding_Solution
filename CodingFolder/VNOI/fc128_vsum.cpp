#include <bits/stdc++.h>
#define endl '\n';
using namespace std;
long long n;
signed main()
{
    cin>>n;
    if (n==1) cout<<2;
    else if (n==2) cout<<1;
    else if (n==3) cout<<2;
    else {
        if (n % 2 == 0) {
            if ((n / 2) % 2 == 0) cout<<0;
            else cout<<1;
        }
        else {
            cout<<2;
        }
    }
}
