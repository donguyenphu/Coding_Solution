#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define f freopen
#define endl '\n'
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll LIM=4e2+5;
const ll N=490;
ll a[N][N];
ll n,x,y,c;
ll tmp[7][7];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    if (fopen("COLOREC.inp","r")) {
        freopen("COLOREC.inp","r",stdin);
        freopen("COLOREC.out","w",stdout);
    }
    memset(a,0,sizeof(a));
    cin>>n;
    for (ll i=1;i<=n;i++) {
        cin>>x>>y>>c;
        a[x+200][y+200]=c;
     //   cnt[x+200][y+200]++;
    }
    ll res=0;
    for (ll i=0;i<=420-1;i++) {
        for (ll j=i+1;j<=420;j++) {
            ll cnt=0;
            memset(tmp,0,sizeof(tmp));
            for (ll k=0;k<=430;k++) {
                if (a[i][k] > 0 && a[j][k] > 0 && a[i][k] != a[j][k]) {
                    /// 1 4,1 2,1 3,2 3,2 4,3 4
                    bool dk1=(min(a[i][k],a[j][k])==1)&&(max(a[i][k],a[j][k])==4);
                    bool dk2=(min(a[i][k],a[j][k])==1)&&(max(a[i][k],a[j][k])==2);
                    bool dk3=(min(a[i][k],a[j][k])==1)&&(max(a[i][k],a[j][k])==3);
                    bool dk4=(min(a[i][k],a[j][k])==2)&&(max(a[i][k],a[j][k])==3);
                    bool dk5=(min(a[i][k],a[j][k])==2)&&(max(a[i][k],a[j][k])==4);
                    bool dk6=(min(a[i][k],a[j][k])==3)&&(max(a[i][k],a[j][k])==4);
                    if (dk1) {
                        cnt+=tmp[2][3];
                        cnt+=tmp[3][2];
                        tmp[a[i][k]][a[j][k]]++;
                    }
                    else if (dk2) {
                        cnt+=tmp[3][4];
                        cnt+=tmp[4][3];
                        tmp[a[i][k]][a[j][k]]++;
                    }
                    else if (dk3) {
                        cnt+=tmp[2][4];
                        cnt+=tmp[4][2];
                        tmp[a[i][k]][a[j][k]]++;
                    }
                    else if (dk4) {
                        cnt+=tmp[1][4];
                        cnt+=tmp[4][1];
                        tmp[a[i][k]][a[j][k]]++;
                    }
                    else if (dk5) {
                        cnt+=tmp[1][3];
                        cnt+=tmp[3][1];
                        tmp[a[i][k]][a[j][k]]++;
                    }
                    else if (dk6) {
                        cnt+=tmp[1][2];
                        cnt+=tmp[2][1];
                        tmp[a[i][k]][a[j][k]]++;
                    }
                }
            }
            res+=cnt;
        }
    }
    cout<<res<<endl;
    return 0;
}
