#include <iostream>
#include <vector>
using namespace std;

int f(string str) {
    int freq[26] = {0};
    int n = str.length();

    int i=0, j=0;
    int ans = 0;
    while(i<n) {
        if(j<n && freq[str[j] - 'a'] == 0) {
            freq[str[j] - 'a']++;
            ans += j-i+1;
            j++;
        }
        else {
            freq[str[i]-'a']--;
            i++;
        }
    }

    return ans;
}

int main() {
    string str;
    cin >> str;

    cout << f(str);
}