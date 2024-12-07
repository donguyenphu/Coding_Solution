#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        LL n, m, x, y;
        scanf("%lli%lli%lli%lli", &n, &m, &x, &y);
        LL cm = ((n&1) != (m&1));
        if (n > m) swap(n, m);
        --n; --m;

        LL res = min(n*x + m*x, n*y + (m - n)*x);
        if (n >= 1) res = min(res, (m - cm)*y + cm*x);
        printf("%lli\n", res);
    }
}
