#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
void printAnagramsTogether(vector<string>& list) {
    int n = list.size();
    unordered_map<unordered_map<char,int>, vector<string> > anagrams;
    for(int i=0; i<n; i++) {
        unordered_map<char, int> freqs;
        for(int j=0; j<list[i].length(); j++) {
            freqs[list[i][j]]++;
        }
        anagrams[freqs].push_back(list[i]);
    }

    unordered_map<unordered_map<char,int>, vector<string> >::iterator it = anagrams.begin();
    while(it != anagrams.end()) {
        vector<string> vec = it->second;
        for(int i=0; i<vec.size(); i++) cout << vec[i] << ", ";
        cout << endl;
    }
}
*/

int main() {
    // vector<string> list;
    // string s;
    // cin >> s;
    // while(s != "-1") {
    //     list.push_back(s);
    //     cin >> s;
    // }
    // printAnagramsTogether(list);
    string t = string(4, 'a'+2);
    cout << t << endl;
    return 0;
}