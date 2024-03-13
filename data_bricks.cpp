#include <iostream>
#include <vector>
using namespace std;

long long f(vector<int>& a, vector<int>& b, int& n) {
    long long cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(a[i]+b[i] == a[j]+b[j]) cnt++;
        }
    }

    return cnt;
}

long long count(vector<int>& a, vector<int>& b, int& n) {
    long long cnt = 0;
    vector<int> c(n);
    for(int i=0; i<n; i++) c[i] = a[i]+b[i];

    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) mp[c[i]]++;

    for(auto it: mp) {
        int n = it.second;
        cnt += (n+1)*n/2;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];

    long long cnt = count(a, b, n);
    cout << "cnt: " << cnt << endl;

    cnt = f(a,b,n);
    cout << "cnt: " << cnt << endl;
}