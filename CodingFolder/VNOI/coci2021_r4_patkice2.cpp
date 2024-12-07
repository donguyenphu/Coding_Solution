#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=2e3+3;
const ll dx[4]={-1,0,1,0};  /// ^ > v <
const ll dy[4]={0,1,0,-1};
const char dc[4]={'^','>','v','<'};
struct dd {
    ll i,j;
    char cc;
};
dd trace[N][N];
ll n,m,cnt=0;
char a[N][N],c[N][N];
bool vis[N][N];
ll si=0,sj=0,ei=0,ej=0;
ll change[N][N];
bool dk(ll i,ll j,ll n,ll m) {
    return (i>=1 && i<=n && j >=1 && j<=m);
}
void bfs(ll sii,ll sjj,ll eii,ll ejj) {
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) change[i][j]=inf;
    }
    change[sii][sjj]=0;
    deque <pll> q;
    q.push_front({sii,sjj});
    while (!q.empty()) {
        pll fr=q.front();
        q.pop_front();
        ll ff=fr.fi,ss=fr.se;
        if (vis[ff][ss]) continue;
        vis[ff][ss]=true;
        for (ll i=0;i<4;i++) {
            ll tmp=0;
            ll fff=ff+dx[i];
            ll sss=ss+dy[i];
            if (dk(fff,sss,n,m)) {
             ///   cout<<fff<<' '<<sss<<endl;
                ll tmp=0;
                if (a[ff][ss] != dc[i]) tmp=1;
                if (a[fff][sss]=='o') tmp=0;
                if (change[fff][sss] > change[ff][ss]+tmp) {
                    change[fff][sss]=change[ff][ss]+tmp;
                    trace[fff][sss]={ff,ss,dc[i]};
                    if (!tmp) q.push_front({fff,sss});
                    else q.push_back({fff,sss});
                }
            }
        }
    }
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
    cin>>n>>m;
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            cin>>a[i][j];
            c[i][j]=a[i][j];
            if (a[i][j]=='o') {
                si=i,sj=j;
            }
            if (a[i][j]=='x') {
                ei=i,ej=j;
            }
        }
    }
    ll c1=ei,c2=ej;
 //   cout<<si<<' '<<sj<<' '<<ei<<' '<<ej<<endl;
   /** for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            cout<<a[i][j];
        }
        cout<<endl;
    } */
    bfs(si,sj,ei,ej);
   // cout<<1<<endl;
   // ll ff=ei,ss=ej;
 ///  cout<<ei<<' '<<ej<<endl;
    while (trace[ei][ej].i != si || trace[ei][ej].j != sj) {
        ll ff=ei,ss=ej;
        ei=trace[ff][ss].i;
        ej=trace[ff][ss].j;
        c[ei][ej]=trace[ff][ss].cc;
     //   cout<<1<<endl;
     //   cout<<ei<<' '<<ej<<endl;
    //    ll ff=ei,ss=ej;
    }
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            if (a[i][j] != c[i][j]) {
              ///  cout<<1<<endl;
                cnt++;
            }
        }
    }
 //   cout<<c1<<' '<<c2<<endl;
    cout<<cnt<<endl;
  ///  cout<<change[c1][c2]<<endl;
  //  cout<<n<<' '<<m<<endl;
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            cout<<c[i][j];
        }
        cout<<endl;
    }
  ///  cout<<111111<<endl;
    return 0;
}
