#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
#define ll long long
#define nline "\n"
#define pb push_back
const ll mod = 1e9+7;

int minCost(int prev, int cur, vector<int>& depth, int& d, int& m, vector<vector<int>>& dp) {
    if(dp[prev][cur] != -1) return dp[prev][cur];
	
	if(cur-prev == d+1) {
		return dp[prev][cur] = (depth[cur]+1+minCost(cur, cur+1, depth, d, m, dp));
	}
	else if(m-prev <= d+1) return dp[prev][cur] = 1;

	return dp[prev][cur] = min(depth[cur]+1+minCost(cur, cur+1, depth, d, m, dp), minCost(prev, cur+1, depth, d, m, dp));
}

void solve() {
	int n,m,k,d;
	cin >> n >> m >> k >> d;

	vector<vector<int>> arr(n+1, vector<int>(m+1));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) cin >> arr[i][j];
	}

	vector<int> prefix(n+1, 0);
	for(int i=1; i<=n; i++) {
		vector<vector<int>> dp(m+2, vector<int>(m+2,1e9));

		// base case
		for(int prev=m-d-1; prev<=m; prev++) {
			for(int i=1; i<=m; i++) dp[prev][i] = 1;
		}

		for(int prev=m; prev>0; prev--) {
			for(int cur=prev+1; cur>0; cur--) {
				if(cur-prev == d+1) dp[prev][cur] = arr[i][cur]+1+dp[cur][cur+1];
				else if(m-prev <= d+1) continue;
				dp[prev][cur] = min(arr[i][cur]+1+dp[cur][cur+1], dp[prev][cur+1]);
			}
		}

		prefix[i] = prefix[i-1]+1+minCost(1, 2, arr[i], d, m, dp);
	}

	// cout << "prefix: ";
	// for(int i=1; i<=n; i++) cout << prefix[i] << " ";
	// cout << endl;

	int minCost = INT_MAX;
	for(int i=k; i<=n; i++) {
		minCost = min(minCost, prefix[i]-prefix[i-k]);
	}

	cout << minCost << endl;

}
 
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

 
    int t;
    cin >> t;
    // cout << "test cases: " << t << "\n";
    while(t--) solve();
}

	// cout << "last bridge at " << prev << endl;
