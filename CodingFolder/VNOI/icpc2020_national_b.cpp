#include <bits/stdc++.h>
#define pll pair<int,int>
using namespace std;
int dxx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int inf=1e8;
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
   int n,m;
  while (cin>>n) {
    cin>>m;
    if (n==0 && m==0) {
      return 0;
    }
    n--;m--;
    vector<vector<int>> dis(n+2,vector<int>(m+2));
    vector<vector<char>> a(n+2,vector<char>(m+2));
    for (int i=0;i<=n;i++) {
      for (int j=0;j<=m;j++) {
          cin>>a[i][j];
          dis[i][j]=inf;
      }
    }
      int mi=inf;
      deque <pll> dq;
      for (int i=0;i<=n;i++) {
          if (a[i][0]=='#') {
            dis[i][0]=0;
            dq.push_front({i,0});
          }
          if (a[i][0]=='.') {
            dis[i][0]=1;
            dq.push_back({i,0});
          }
      }
      for (int i=0;i<=m;i++) {
          if (a[n][i]=='#') {
            dis[n][i]=0;
            dq.push_front({n,i});
          }
          if (a[n][i]=='.') {
            dis[n][i]=1;
            dq.push_back({n,i});
          }
      }
      while (!dq.empty()) {
          pll fr=dq.front();dq.pop_front();
          int ff=fr.first,ss=fr.second;
          for (int i=0;i<8;i++) {
              int fff=dxx[i]+ff,sss=dyy[i]+ss;
              if (fff>=0 && fff <= n && sss >= 0 && sss <= m && a[fff][sss] != '@') {
                  int tmp=0;
                  if (a[fff][sss]=='.') tmp=1;
                  if (dis[fff][sss] > dis[ff][ss]+tmp) {
                      dis[fff][sss]=dis[ff][ss]+tmp;
                      if (!tmp) dq.push_front({fff,sss});
                      else dq.push_back({fff,sss});
                  }
              }
          }

      }
      for (int i=0;i<=m;i++) mi=min(mi,dis[0][i]);
      for (int i=0;i<=n;i++) mi=min(mi,dis[i][m]);
      // dq.clear();
      cout<<(mi>=inf ? -1 : mi)<<endl;
  }
  return 0;
}
