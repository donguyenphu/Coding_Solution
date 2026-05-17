#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
long long way[N], n;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // base case
    way[1] = 0; // cant be the same cell
    way[2] = 6;  // 4C2 = 4 * (4 - 1)/2
    for (int i = 3; i <= 10002; i++) {
        long long total = i * i;
        // satisfy = total - way they attack each other (start and end point of L shape)
        // Note: way they attack = count the number of 2 * 3 board on i * i board then * 2 (2 L in a 2 * 3 board)
        // board can be 2 * 3 or 3 * 2
        way[i] = (total * (total-1))/2 - 2 * 2 * (i - 3 + 1) * (i - 2 + 1);
    }
    cin>>n;
    for (int i = 1; i <= n; i++) cout<<way[i]<<endl;
    return 0;
}

