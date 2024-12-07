#include <bits/stdc++.h>
#define ll long long
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	ll n;
	cin>>n;
	if (n==0) cout<<"0";
	else {
		if (n%1024==0) {
			if ((n/1024)%4==0) cout<<n/1024;
			else if ((n/1024)%4 !=0) {
				for (ll i=1;i<=n;i++) {
					if ((n/1024)<=4*i) {
						cout<<4*i;
						break;
					}
				}
			}
		}
		else {
			if ((n/1024)%4==0) cout<<(n/1024)+4;
			if ((n/1024)%4 !=0) {
				for (ll i=1;i<=n;i++) {
					if ((n/1024)<=4*i) {
						cout<<4*i;
						break;
					}
				}
			}
		}
	}
	return 0;
}
