#include<bits/stdc++.h>
using namespace std;
int t;
long long f[11][93][1002][2];
int dig[100];
long long dp(int m,int pos,int remsum,int remnum,bool lower) {
    if (!pos) {
        return (remsum%m==0 && !remnum);
    }
    long long &res=f[pos][remsum][remnum][lower];
    if (res != -1) return res;
    res=0;
    int lim=(lower ? 9 : dig[pos]);
    for (int j=0;j<=lim;j++) {
        bool ok2=(lower || j < lim);
        res=(res+dp(m,pos-1,(remsum+j),(remnum*10+j)%m,ok2));
    }
    return res;
}
long long calc(int n,int rem) {
    memset(f,-1,sizeof(f));
    int tm=0;
    int ff=n;
    while (ff > 0) {
        dig[++tm]=ff%10;
        ff/=10;
    }
    return dp(rem,tm,0,0,false);
}
int m;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (int test=1;test<=t;test++) {
        int a,b;
        cin>>a>>b;
        cin>>m;
        cout<<"Case "<<test<<": "<<calc(b,m)-calc(a-1,m)<<endl;
    }
   /// TIME
  return 0;
}
