#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    cin.tie()->sync_with_stdio(0);
    vector <int> vec;
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        if (n==1) vec.push_back(0);
        else {
            if (n % 3 !=0) vec.push_back(-1);
            else {
                int tmp2=0,tmp3=0,fi=n;
                while (n%2==0) {
                    tmp2++;
                    n/=2;
                }
                while (fi%3==0) {
                    tmp3++;
                    fi/=3;
                }
                while (n%3==0) {
                    n/=3;
                }
                if (n>1) vec.push_back(-1);
                else if (n==1) {
                    if (tmp3<tmp2) vec.push_back(-1);
                    else if (tmp3>=tmp2) {
                        vec.push_back(tmp3+(tmp3-tmp2));
                    }
                }
            }
        }
    }
    for (int i=0;i<vec.size();i++) {
        cout<<vec[i]<<endl;
    }
}
