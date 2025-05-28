#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge {
    int  v1,v2,weight,num;
};
int  pac[200004],siz[200004],height[200004],ans[200004];
int  pa[200004][35],ma[200004][35];
int  nn,mm,uu,vv,ww,as=0;
vector <pair<int ,int >> rev[200004];
vector <Edge> eg;
int  fin(int  aa) {
    if (aa == pac[aa]) return aa;
    int temp = fin(pac[aa]);
    pac[aa] = temp;
    return temp;
}
bool join(int  u,int  v) {
    u=fin(u);
    v=fin(v);
    if (u==v) return false;
    if (siz[u] < siz[v]) swap(u,v);
    siz[u]+=siz[v];
    pac[v]=u;
    return true;
}
void dfs(int  u,int  pre) {
    for (int i=1;i<=18;i++) {
        pa[u][i]=pa[pa[u][i-1]][i-1];
        ma[u][i]=max(ma[u][i-1],ma[pa[u][i-1]][i-1]);
    }
    for (auto it : rev[u]) {
        if (it.first==pre) continue;
        pa[it.first][0]=u;
        ma[it.first][0]=it.second;
        height[it.first]=height[u]+1;
        dfs(it.first,u);
    }
}
int lca(int  u,int  v) {
    if (u==v) return 0;
    if (height[u] < height[v]) swap(u,v);
    int  c=u;
    int  fit=0,fit2=0;
    int  val=abs(height[c]-height[v]);
    if (val >= 1) {
        int  ckk=__lg(val);
        for (int  i=0;i<=ckk;i++) {
            if ((val>>i)&1) {
                fit=max(fit,ma[c][i]);
                c=pa[c][i];
            }
        }
    }
    if (c==v) return max(fit,fit2);
    for (int  i=18;i>=0;i--) {
        if (pa[v][i] != pa[c][i]) {
            fit=max(fit,ma[c][i]);
            fit2=max(fit2,ma[v][i]);
            v=pa[v][i];
            c=pa[c][i];
        }
    }
    fit=max(fit,ma[c][0]);
    fit2=max(fit2,ma[v][0]);
    return max(fit,fit2);
}
bool cmp(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>nn>>mm;
    for (int  i=1;i<=mm;i++) {
        cin>>uu>>vv>>ww;
        eg.push_back({uu,vv,ww,i});
        pac[i]=i;
        siz[i]=0;
    }
    siz[nn]=0;
    pac[nn]=nn;
    sort(eg.begin(), eg.end(), cmp);
    for (auto it : eg) {
        if (join(it.v1,it.v2)) {
            as+=it.weight;
            rev[it.v1].push_back({it.v2,it.weight});
            rev[it.v2].push_back({it.v1,it.weight});
        }
    }
    dfs(1,-1);
    for (auto it : eg) ans[it.num]=as+it.weight-lca(it.v1,it.v2);
    for (int  i=1;i<=mm;i++) cout<<ans[i]<<'\n';
    return 0;
}
