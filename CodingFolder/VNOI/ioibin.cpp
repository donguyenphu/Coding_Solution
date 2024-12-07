#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
#define f freopen
#define endl '\n'
#define pb push_back
#define pint pair<int,int>
using namespace std;
const int N=1e4+3;
int siz[N],pa[N];
vector <int> str[N];
map <pint,bool> in;
void make(int n) {
    for (int i=1;i<N;i++) {
        siz[i]=1;
        pa[i]=i;
       /// in[{i,i}]=true;
    }
}
int fin(int a) {
    return (a==pa[a] ? a : fin(pa[a]));
}
void uni(int a,int b) {
    a=fin(a);
    b=fin(b);
    if (a==b) {
        in[{a,b}]=true;
        in[{b,a}]=true;
        return ;
    }
    if (siz[a] < siz[b]) swap(a,b);
    siz[a]+=siz[b];
    pa[b]=a;
  /**  str[a].pb(b);
    for (auto it : str[a]) {
        in[{it,b}]=true;
        in[{b,it}]=true;
    } */
    return ;
  //  in[a][b]=true;
//     in[b][a]=true;
//        fi--;
  //  maxn=max(maxn,siz[a]);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        f("p1.inp","r",stdin);
        f("p1.out","w",stdout);
    }
    int p;
    cin>>p;
///    fi=n;
    make(N);
    for (int i=1;i<=p;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        if (z==1) {
            uni(x,y);
        }
        else if (z==2) {
            x=fin(x);
            y=fin(y);
            if (x==y) {
                cout<<1<<endl;
            }
            else {
                cout<<0<<endl;
            }
        }
    }

    return 0;
}
