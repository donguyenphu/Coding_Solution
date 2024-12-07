#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll inf=1e17;
const ll N=1e5+4;
ll a[N],b[N],n;
ll mi=inf;
bool have1=false,have2=false;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("p1.inp","r")) {
        freopen("p1.inp","r",stdin);
        freopen("p1.out","w",stdout);
    }
    cin>>n;
    for (ll i=1;i<=n;i++) {
        cin>>a[i];
        if (!a[i]) have1=true;
    }
    for (ll j=1;j<=n;j++) {
        cin>>b[j];
        if (!b[j]) have2=true;
    }
    if (have1) for (ll i=1;i<=n;i++) mi=min(mi,abs(b[i]));
    if (have2) for (ll i=1;i<=n;i++) mi=min(mi,abs(a[i]));
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
  /*  for (ll i=1;i<=n;i++) {
        cout<<a[i]<<' ';
    }
    cout<<endl;
    for (ll i=1;i<=n;i++) {
        cout<<b[i]<<' ';
    }
    cout<<endl; */
    for (ll i=1;i<=n;i++) {
        /// a[i]
        /// abs max-min
        if (a[i] >= 0) {
            ll l=1,r=n;
            ll l2=1,r2=n;
            ll id1=-1,id2=-1,id3=-1;
            ll diff1=inf,diff2=inf,diff3=inf;
            ll l1=1,r1=n;
            while (l1 <= r1) {
                ll mid=(l1+r1)>>1;
                if (b[mid] >= 0) {
                    id1=mid;
                    r1=mid-1;
                }
                else l1=mid+1;
            }
            /// < 0
            while (l <= r) {
                ll mid=(l+r)>>1;
                if (b[mid] >= 0) {
                    r=mid-1;
                }
                /// < >=0
                else {
                    if (abs(b[mid]) >= a[i]) {
                        id2=mid;
                        l=mid+1;
                    }
                    else r=mid-1;
                }
            }
            while (l2 <= r2) {
                ll mid=(l2+r2)>>1;
                if (b[mid] >= 0) {
                    r2=mid-1;
                }
                /// < <0
                else {
                    if (abs(b[mid]) < a[i]) {
                        id3=mid;
                        r2=mid-1;
                    }
                    else l2=mid+1;
                }
            }
            if (id1 > 0) diff1=abs(a[i]+b[id1]);
            if (id2 > 0) diff2=abs(a[i]+b[id2]);
            if (id3 > 0) diff3=abs(a[i]+b[id3]);
            if (id1==inf) id1=-1;
            if (id2==inf) id2=-1;
            if (id3==inf) id3=-1;
          ///  cout<<id1<<' '<<id2<<' '<<id3<<endl;
          ///  cout<<diff1<<' '<<diff2<<' '<<diff3<<endl;
            mi=min(mi,min({diff1,diff2,diff3}));
        }
        else if (a[i] < 0) {
            ll l=1,r=n;
            ll l2=1,r2=n;
            ll id1=-1,id2=-1,id3=-1;
            ll diff1=inf,diff2=inf,diff3=inf;
            ll l1=1,r1=n;
            while (l1 <= r1) {
                ll mid=(l1+r1)>>1;
                if (b[mid] < 0) {
                    id1=mid;
                    l1=mid+1;
                }
                else if (b[mid] >= 0) r1=mid-1;
            }
            /// > 0
            /// >= 0
            while (l <= r) {
                ll mid=(l+r)>>1;
                if (b[mid] < 0) {
                    l=mid+1;
                }
                /// >= <= 0
                else {
                    if (abs(b[mid]) >= abs(a[i])) {
                        id2=mid;
                        r=mid-1;
                    }
                    else l=mid+1;
                }
            }
            /// > 0 <= 0
            while (l2 <= r2) {
                ll mid=(l2+r2)>>1;
                if (b[mid] < 0) {
                    l2=mid+1;
                }
                /// < <0
                else {
                    if (abs(b[mid]) <= abs(a[i])) {
                        id3=mid;
                        l2=mid+1;
                    }
                    else r2=mid-1;
                }
            }
            if (id1 > 0) diff1=abs(a[i]+b[id1]);
            if (id2 > 0) diff2=abs(a[i]+b[id2]);
            if (id3 > 0) diff3=abs(a[i]+b[id3]);
            if (id1==inf) id1=-1;
            if (id2==inf) id2=-1;
            if (id3==inf) id3=-1;
          ///  cout<<id1<<' '<<id2<<' '<<id3<<endl;
          ///  cout<<diff1<<' '<<diff2<<' '<<diff3<<endl;
            mi=min(mi,min({diff1,diff2,diff3}));
        }
    }
  ///  cout<<b[1]<<endl;
    cout<<mi<<endl;
    return 0;
}
