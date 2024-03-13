#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLongestSubsequence(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if ((arr[j] - arr[i]) % 2 == 0) {
                dp[i][j] = j - i + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10};
    cout << "Length of longest subsequence: " << findLongestSubsequence(arr) << endl;
    return 0;
}
