#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=2e5 + 10;
int n,m,q,id[N],ans[N];
pii a[N],qu[N];
vector<int> ke[N];
int pa(int v)
{
    return id[v]<0 ? v : id[v]=pa(id[v]);
}
void unit(int a,int b,int qe)
{
    a=pa(a);
    b=pa(b);
    if(b != a)
    {
        if(id[a] > id[b]) swap(a,b);
        id[a]+=id[b];
        id[b]=a;
        if(ke[b].size() > ke[a].size()) swap(ke[a],ke[b]);
        for(int i:ke[b])
        {
            if(ans[i] == 0 && pa(qu[i].fi) == pa(qu[i].se)) ans[i] = qe + 1;
            ke[a].pb(i);
        }
        ke[b].clear();
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    forinc(i,1,n) id[i]=-1;
    forinc(i,1,m) cin>>a[i].fi>>a[i].se;
    forinc(i,1,q)
    {
        cin>>qu[i].fi>>qu[i].se;
        if(qu[i].fi == qu[i].se) ans[i]=1;
        ke[qu[i].fi].pb(i);
        ke[qu[i].se].pb(i);
    }
    forinc(i,1,m) unit(a[i].fi,a[i].se,i);
    forinc(i,1,q) cout<<ans[i]-1<<"\n";

}
