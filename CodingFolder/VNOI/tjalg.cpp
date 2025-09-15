#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 2;
long long n, m, u, v, scc = 0, low[N], num[N], tim = 0;
vector <long long> adj[N];
bool del[N];
stack <long long> st;
void dfs(long long u) {
    low[u] = num[u] = ++tim;
    st.push(u);
    for (auto it : adj[u]) {
        if (del[it]) continue;
        if (!num[it]) {
            dfs(it);
            low[u] = min(low[u], low[it]);
        }
        else {
            low[u] = min(low[u], num[it]);
        }
    }
    if (low[u] == num[u]) {
        scc++;
        long long tmp = -1;
        do {
            tmp = st.top();
            st.pop();
            del[tmp] = true;
        }while(tmp != u);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i = 1; i <= n; i++) del[i] = false;
    for (long long i = 1; i <= m; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs(i);
    }
    cout<<scc;
    return 0;
}
