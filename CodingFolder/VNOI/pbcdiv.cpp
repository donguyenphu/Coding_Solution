#include <iostream>
#include <algorithm>
#include <cstdio>
#define calc(a) ((a)/12+(a)/30-((a)/60)*2)
using namespace std;
int main()
{
    int test;
    long long a,b;
    cin >> test;
    while (test--)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",calc(b)-calc(a-1));
    }
    return 0;
}
