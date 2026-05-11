// Brute Force version (N^2 * N!)
#include <bits/stdc++.h>

using namespace std;
const int N = 2e1 + 5;
const int MOD = 1e9 + 7;

int n, m, a, b, result = 0;
vector <int> adj[N];

bool exist(int element, vector <int> store) {
  for (int i = 0; i < store.size(); i++) {
    if (store[i] == element) return true;
  }
  return false;
}

void dfs(int current, int length, vector <int> element) {
  if (current == n) {
    if (length != n) return ;
    else {
      result++;
      return ;
    }
  }
  else {
    for (auto it: adj[current]) {
      if (!exist(it, element)) {
        vector <int> temp = element;
        temp.push_back(it);
        dfs(it, temp.size(), temp);
      }
    }
  }
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>n>>m;

  for (int i = 1; i <= m; i++) {
    cin>>a>>b;
    adj[a].push_back(b);
  }
  vector <int> initial = {1};
  dfs(1, 1, initial);
  cout<<result;
  return 0;
}
