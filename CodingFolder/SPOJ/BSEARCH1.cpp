#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
int q,n,a[N],id;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=q;i++) {
		cin>>id;
		int l=1,r=n;
		int ans=-1;
		while (l <= r) {
			int mid=(l+r)>>1;
			if (a[mid] >= id) {
				ans=mid;
				r=mid-1;
			}
			else {
				l=mid+1;
			}
		}
		if (ans == -1) {
            cout<<ans<<'\n';
		}
		else {
            cout<<(a[ans] == id ? ans-1 : -1)<<'\n';
		}
	}
	return 0;
}
