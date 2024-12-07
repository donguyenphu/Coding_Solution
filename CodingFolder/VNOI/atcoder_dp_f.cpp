#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define f freopen
using namespace std;
const ll N=3e3+2;
ll dp[N][N];
void sth(string a,string b,ll m,ll n) {
    ll dp[m+1][n+1];
    for (ll i=0;i<=m;i++) {
        for (ll j=0;j<=n;j++) {
            if (i==0 || j==0) {
                dp[i][j]=0;
               /// continue;
            }
            else if (a[i-1] == b[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    ll index=dp[m][n];

    char lcs[index+1];

    lcs[index]='\0';
    ll i=m;
    ll j=n;
    while ( i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            lcs[index-1]=b[j-1];
            i--;
            j--;
            index--;
        }
        else {
            if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            }
            else j--;
        }
    }
    cout<<lcs;
}
signed main() {
    cin.tie()->sync_with_stdio(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    string a,b;
    cin>>a;
    cin>>b;
    ll m=a.size();
    ll n=b.size();
 /*   for (ll i=0;i<=m;i++) {
        for (ll j=0;j<=n;j++) {
            if (i==0 || j==0) {
                dp[i][j]=0;
            }
            else {
                if (a[i]==b[j]) {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[m][n]; */
    sth(a,b,m,n);
    return 0;
}
