#include <bits/stdc++.h>
using namespace std;
void process() {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;

    for(int C = 0; C <= 10000; ++C) {
        if(((A + C) * X) % Y != 0){
            continue;
        }
        int D = ((A + C) * X) / Y - B;
        if(D >= 0) {
            cout << C + D << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int tests;
    cin >> tests;
    while(tests>0) {
        process();
        tests--;
    }
    return 0;
}
