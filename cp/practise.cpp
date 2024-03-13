#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
 
#define ll long long
#define endl "\n"
#define pb push_back
const ll mod = 1e9+7;

void solve() {
    ll n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    ll sum=0; // num of pairs having sum x+y=arr[i] for all i
    for(int i=0; i<n; i++) sum += (arr[i]/2+1);

    ll subtr=0; // num of pairs having subtraction y-x=arr[i] for all i
    for(int i=0; i<n; i++) subtr += c-arr[i]+1;

    ll odd=0, even=0, intr=0; // intr is intersection of sum and subtr
    for(int i=0; i<n; i++) {
        odd += (arr[i]%2); even += (arr[i]%2 == 0);
        (arr[i]%2) ? intr += odd : intr += even;
    }

    cout << ((c+1)*(c+2))/2 - (sum+subtr-intr) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    // cout << "t: " << t << endl;
    while(t--) solve();
}