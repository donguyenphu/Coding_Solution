#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e1+3;
const ll K=15e2+2;
const ll MOD=1e9+7;
const int BASE=311;
ll has[N][N][K];
ll pw[N],n,k;
string g;
ll dp[N][K];
string mat[N][K];
bool can[N][K];
void pre() {
    pw[0]=1;
    for (int i=1;i<=52;i++) {
        pw[i]=BASE*pw[i-1]%MOD;
    }
}
void buildhash(string s,ll i,ll j) {
  for (ll k=1;k<s.size();k++) {
    has[k][i][j]=(BASE*has[k-1][i][j]%MOD+s[k])%MOD;
  }
}
ll gethash(ll l,ll r,ll i,ll j) {
  return (has[r][i][j]-has[l-1][i][j]*pw[r-l+1]%MOD + MOD)%MOD;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre();
  cin>>n>>k;
  for (ll i=1;i<=n;i++) {
    for (ll j=1;j<=k;j++) {
      cin>>mat[i][j];
      mat[i][j]=" "+mat[i][j];
      string rr=mat[i][j];
      buildhash(rr,i,j);
    }
  }
  for (ll i=1;i<=n;i++) {
    for (ll j=1;j<=k;j++) {
      dp[i][j]=0;
      can[i][j]=false;
    }
  }
  // for (ll i=1;i<=n;i++) {
  //   for (ll j=1;j<=k;j++) {
  //     cout<<mat[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
  for (ll i=1;i<=k;i++) dp[1][i]=1;

  for (ll i=2;i<=n;i++) {
    for (ll j=1;j<=k;j++) {
      for (ll r=1;r<=k;r++) {
        // ll siz=mat[i-1][r].size()-1;
        bool dk=(gethash(1,i-1,i,j)==gethash(1,i-1,i-1,r));
        bool dk2=(gethash(2,i,i,j)==gethash(1,i-1,i-1,r));
        bool dk3=(dk || dk2);
        if (dk3) {
          // cout<<1<<endl;
          can[i][j]=true;
          // dp[i][j]=((dp[i][j]%MOD)*(dp[i-1][r]%MOD))%MOD;
          dp[i][j]=(dp[i][j]+dp[i-1][r])%MOD;
        }
      }
    }
  }
  // for (ll i=1;i<=k;i++) cout<<dp[1][i]<<' ';
  // cout<<endl;
  // for (ll i=1;i<=k;i++) cout<<dp[n][i]<<' ';
  // cout<<endl;
  // for (ll i=1;i<=n;i++) {
  //   for (ll j=1;j<=k;j++) {
  //     cout<<dp[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
  ll res=0;
  for (ll i=1;i<=k;i++) {
    // if (can[n][i])
    res=(res+dp[n][i])%MOD;
  }
  cout<<res;
  return 0;
}
