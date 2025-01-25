#include <bits/stdc++.h>
#define ll long long
#define NAME "p1"
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l,ll r) {
    assert(l <= r);
    ll siz=(r-l+1);
    return l+rd()%siz;
}
const ll test=100;
void MAKE() {
    ofstream cout(NAME".inp");
    /// put your code for your programs here
    return ;
}
signed main()
{
    srand(time(0));
    for (ll i=1;i<=test;i++) {
        MAKE();
        system(NAME"_trau.exe");
        system(NAME".exe");
        if (system("fc "NAME".out "NAME".ans") != 0) {
            cout<<"TEST"<<' '<<i<<' '<<"WA"<<endl;
            return 0;
        }
        cout<<"TEST"<<' '<<i<<' '<<"AC"<<endl;
    }
    return 0;
}
