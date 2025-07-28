#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e2+90;
ll n,r;
bool m[N][N];
char a[N][N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(m,false,sizeof(m));
    cin>>n>>r;
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=r;j++) {
            cin>>a[i][j];
            if (a[i][j]=='#') m[i][j]=true;
        }
    }
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=r;j++) {
            if (a[i][j]=='#') {
                m[i][j+1]=m[i+1][j]=m[i+1][j+1]=true;
            }
        }
    }
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=r;j++) {
            cout<<(m[i][j] ? "#" : ".");
        }
        cout<<endl;
    }
    return 0;
}
