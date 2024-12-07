#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=3e1+3;
const ll K=5e1+3;
ll t,dp[N][N][K];
void pre() {
  //  memset(dp,0,sizeof(dp));
    ll n=30;
    ll m=30;
    ll k=50;
   /// cout<<n<<' '<<m<<' '<<k<<endl;
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            for (ll g=1;g<=k;g++) {
                dp[i][j][g]=inf;
            }
        }
    }
   /// for (ll i=1;i<=n;i++) for (ll j=1;j<=m;j++) dp[i][j][0]=0;
   // for (ll i=1;i<=m;i++) dp[1][i][1]=1;
   // for (ll i=1;i<=n;i++) dp[i][1][1]=1;
  //  dp[0][0][0]=0;
    /// break length^2
  //  dp[1][1][0]=0;
    dp[1][1][1]=0;
   /// cout<<dp[4][5][0]<<endl;
   ll kk=k;
 ///   for (ll kk=1;kk<=k;kk++) {
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            for (ll g=min(kk,i*j);g>=1;g--) {
                if (i*j==g) dp[i][j][g]=0;
                else {
                    ll dec=min(i*j,kk);
                    //// cang it, cang can nhieu thao tac
                    for (ll h=1;h<=j-1;h++) {
                        if (h*i <= g) {
                            dp[i][j][g]=min(dp[i][j][g],dp[i][j-h][g-h*i]+i*i);
                            if (i*(j-h) >= g) {
                                dp[i][j][g]=min(dp[i][j][g],dp[i][j-h][g]+i*i);
                            }
                          ///  dp[i][j][g]=min(dp[i][j][g],dp[i][h][g-h*i]+i*i);
                        }
                         if (i*(j-h) >= g) {
                                dp[i][j][g]=min(dp[i][j][g],dp[i][j-h][g]+i*i);
                            }
                    }
                    for (ll w=1;w<=i-1;w++) {
                        if (w*j <= g) {
                            dp[i][j][g]=min(dp[i][j][g],dp[i-w][j][g-w*j]+j*j);
                            if ((i-w)*j >= g) {
                                dp[i][j][g]=min(dp[i][j][g],dp[i-w][j][g]+j*j);
                            }
                          /// dp[i][j][g]=min(dp[i][j][g],dp[w][j][g-w*j]+j*j);
                        }
                        if ((i-w)*j >= g) {
                                dp[i][j][g]=min(dp[i][j][g],dp[i-w][j][g]+j*j);
                            }
                    }
                }
            }
        }
    }
  ///  }
    return ;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    pre();
    cin>>t;
    while (t--) {
        ll i,j,g;
        cin>>i>>j>>g;
      ///  cout<<i<<' '<<j<<' '<<g<<endl;
        cout<<dp[i][j][g]<<endl;
    }
    return 0;
}
