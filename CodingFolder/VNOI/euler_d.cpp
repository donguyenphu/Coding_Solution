#include <bits/stdc++.h>
using namespace std;
int n, child[200001], a[200001], bac[200001], lab[200001], c[200001], ans[200001];
int bit[200001], tt[200001][3];
int tim = 0;
int u,v;
vector <int> adj[200002];
vector <int> qr[200002];
map <int,int> mp;
vector <int> cmress = {-1};
void dfs(int u, int pre) {
    lab[u] = ++tim;
    bac[lab[u]] = u;
    for (auto it : adj[u]) {
        if (it == pre) continue;
        else {
            child[u]++;
            dfs(it, u);
            child[u] += child[it];
        }
    }
}
void up(int u,int val) {
    int idx=u;
    while (idx <= n) {
        bit[idx]+=val;
        idx+=(idx & (-idx));
    }
}
int get(int u) {
    int idx=u,anss=0;
    while (idx > 0) {
        anss+=bit[idx];
        idx-=(idx & (-idx));
    }
    return anss;
}
void qry(int val,int idx) {
    if (!tt[val][0]) {
        tt[val][0]=idx;
        up(idx,1);
        return ;
    }
    else {
        tt[val][1]=tt[val][0];
        tt[val][0]=idx;
        up(tt[val][0],1);
        up(tt[val][1],-1);
    }
    return ;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>c[i];
        if (!mp[c[i]]) cmress.push_back(c[i]);
        mp[c[i]]++;
    }
    sort(cmress.begin(), cmress.end());
    for (int i = 1; i <= n; i++) {
        c[i] = lower_bound(cmress.begin(), cmress.end(), c[i]) - cmress.begin();
    }
    for (int i = 1; i <= n-1; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    for (int i = 1;i <= n; i++) {
        a[i] = c[bac[i]];
    }
    for (int i = 1; i <= n; i++) {
        qr[lab[i]+child[i]].push_back(lab[i]);
    }
    for (int i = 1; i <= n; i++) {
        qry(a[i], i);
        for (auto it : qr[i]) {
            ans[bac[it]] = get(i) - get(it-1);
        }
    }
    for (int i = 1; i <= n; i++) cout<<ans[i]<<' ';
    return 0;
}
