#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void printPermutations(int ind, vector<string>& vec) {
    if(ind == vec.size()) {
        for(string str: vec) cout << str << ", ";
        cout << endl;
    }

    for(int i=ind; i<vec.size(); i++) {
        swap(vec[ind], vec[i]);
        printPermutations(ind+1, vec);
        swap(vec[ind], vec[i]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i=0; i<n; i++) cin >> vec[i];
    // string s;
    // cin >> s;
    printPermutations(0, vec);
}