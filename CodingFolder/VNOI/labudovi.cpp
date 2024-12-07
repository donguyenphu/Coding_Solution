#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
#define pll pair<ll,ll>
#define tlll tuple <ll,ll,ll>
#define maximize(a,b) a=max(a,b)
#define minimize(a,b) a=min(a,b)
using namespace std;
const ll N=15e2+4;
char ch[N][N];
ll dp[N][N];
ll n,m;
const ll INF=1e16;
ll tmp=0;
ll a=0,b=0,x=0,y=0;
ll ans=LONG_MAX;
const ll dx[4]= { 0,0,-1,1};
const ll dy[4]= {-1,1,0,0};
queue <pll> q;
ll cnt=0;
bool visited[N][N];
queue<pll> chp;
bool dk(ll i,ll j) {
    return (i >= 1 && i<= n && j>=1 && j<=m);
}
bool checkpath(ll k) {
    memset(visited,false,sizeof(visited));
    visited[a][b]=true;
    chp.push({a,b});
    while (!chp.empty()) {
        pll fr=chp.front();
        chp.pop();
        ll fir=fr.first;
        ll sec=fr.second;
        for (ll i=0;i<4;i++){
            ll ch1=fir+dx[i];
            ll ch2=sec+dy[i];
            if (dp[ch1][ch2] <= k && !visited[ch1][ch2]) {
                chp.push({ch1,ch2});
                visited[ch1][ch2]=true;
           //     if (ch1==x && ch2==y) return true;
            }
        }
    }
    return visited[x][y];
}
void bfs(ll a,ll b,ll x,ll y)
{
    while (!q.empty()) {
        pll fr=q.front();
        q.pop();
        ll fir=fr.first;
        ll sec=fr.second;
        for (ll i=0;i<4;i++) {
            if (dk(fir+dx[i],sec+dy[i])) {
                if (dp[fir+dx[i]][sec+dy[i]] > dp[fir][sec]+1) {
                    dp[fir+dx[i]][sec+dy[i]]=dp[fir][sec]+1;
                    q.push({fir+dx[i],sec+dy[i]});
                }
            }
        }
    }
}
signed main()  /// 2
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    memset(dp,0x3f3f,sizeof(dp));
    cin>>n>>m;
 /*   for (ll i=1;i<n;i++) {
        for (ll j=1;j<=m;++j) {
            if (dp[i][j] >= INF) {
                cout<<-1<<" ";
            }
            else cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } */
    for (ll i=1;i<=n;i++) {
        for (ll j=1;j<=m;j++) {
            cin>>ch[i][j];
            if (ch[i][j]=='L') {
                tmp++;
                if (tmp==1) {
                    a=i;
                    b=j;
                }
                else if (tmp==2) {
                    x=i;
                    y=j;
                }
            }
            if (ch[i][j] != 'X') {
                dp[i][j]=0;
                q.push({i,j});
            }
        }
    }
 ///   cerr<<a<<" "<<b<<endl;
 ///   cerr<<x<<" "<<y<<endl;
    bfs(a,b,x,y);
    ll l=1,r=n*m;
   /// cout<<r<<endl;
    while (l<=r) {
        ll mid=(l+r)/2;
        if (checkpath(mid)) {
            r=mid-1;
        }
        else l=mid+1;
    }
 //   cout<<r<<endl;
 //   cout<<l<<endl;
    r++;
    cout<<r;
    return 0;
}
