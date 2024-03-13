#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll mod = 1e9+7;

void solve() {
    int a, b;
    cin >> a >> b;

    while(a>0 && b>0) {
        if(a>b) {
            a -= 2;
            b -= 1;
        }
        else a -= 1, b-= 2;
    }

    if(!a && !b) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
