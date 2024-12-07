#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll cnt=0;
    for (ll i=0;i<s.size()-5;i++) {
        if (s.substr(i,5)=="virus") cnt++;
    }
    cout<<cnt<<endl;
}
