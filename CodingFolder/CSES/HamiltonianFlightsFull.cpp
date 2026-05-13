#include <bits/stdc++.h>
using namespace std;

const int N = 2e1 + 1;
const int MOD = 1e9 + 7;

int n, m, a, b;
// mask[State][Current vertice]:
// Number of way to go with path state State with current vertice is Current vertice
int mask[(1<<N)][N];

vector <int> reverseEdge[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>n>>m;
  for (int i = 1; i <= m; i++) {
    cin>>a>>b;
    reverseEdge[b].push_back(a);
  }
  // only way to stay at the start point is 1;
  mask[1<<0][1] = 1;

  for (int MASK = 2; MASK <= (1<<n) - 1; MASK++) {
    if (__builtin_popcount(MASK) == 1) { // Wrong cases (initial vertices != 1)
      continue;
    }
    else if (((MASK >> (n-1)) & 1) && __builtin_popcount(MASK) != n) { // (end point must be n -> n appears while number of vertices != n is wrong)
      continue;
    }
    else if (!((MASK >> (0)) & 1)) { // 1 must be exist as a starting point -> wrong cases when no 1 in the path
      continue;
    }
    else {
      for (int pos = 1; pos < n; pos++) {
        if ((MASK>>pos) & 1) {
          for (auto it: reverseEdge[pos + 1]) {
            if ((MASK>>(it - 1)) & 1) {
              int prevMASK = MASK - (1<<(pos));
            /*
                imagine 1->3->2
                current vertice is 2, we check all the vertices that GO TO 2 and also EXIST IN THE PATH
                -> get the previous state, which is WITHOUT 2 and the current vertice of previous state is the vertice that GO TO 2
            */
              mask[MASK][pos + 1] += mask[prevMASK][it];
              mask[MASK][pos + 1]  %= MOD;
            }
          }
        }
      }
    }
  }
  cout<<mask[(1<<n)-1][n] % MOD; // ways of all vertices and end point is n
  return 0;
}
