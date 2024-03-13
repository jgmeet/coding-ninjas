#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mod = 1e9 + 7;
int base = 29;

vector<int> stringMatch(string text, string pattern) {
    int t = text.length(), p = pattern.length();
    int N = max(t, p);
    vector<long long> pow(N + 1);
    pow[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow[i] = (pow[i - 1] * base) % mod;
    }

    long long h_p = 0;
    for (int i = 0; i < p; i++) {
        h_p = (h_p + (pattern[i] - 'a' + 1) * pow[i]) % mod;
    }

    vector<long long> h_t(t+1, 0);
    for (int i = 1; i <= t; i++) {
        h_t[i] = (h_t[i - 1] + (text[i-1] - 'a' + 1) * pow[i-1]) % mod;
    }

    vector<int> ans;
    for (int i = 0; i + p <= t; i++) {
        long long cur_h = (h_t[i + p] - h_t[i] + mod) % mod;

        if ((pow[i]*h_p)%mod == cur_h) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    string text = "ababcab";
    string pattern = "ab";
    vector<int> result = stringMatch(text, pattern);
    cout << result.size() << endl;
    for (int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
