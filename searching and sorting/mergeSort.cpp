#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int s, int mid, int e) {
    vector<int> sortedArr;
    int i=s, j=mid+1;
    int numConv = 0;
    while(i<=mid && j<=e) {
        if(arr[i] < arr[j]) {
            sortedArr.push_back(arr[i]);
            i++;
        }
        // left is greater than right
        else {
            sortedArr.push_back(arr[j]);
            numConv += mid-i+1;
            j++;
        }
    }

    while(i<=mid) {
        sortedArr.push_back(arr[i]);
        i++;
    }
    while(j<=e) {
        sortedArr.push_back(arr[j]);
        j++;
    }

    for(int i=0; i<sortedArr.size(); i++) {
        arr[i+s] = sortedArr[i];
    }

    return numConv;
}

int mergeSort(vector<int>& arr, int s, int e) {
    int cnt = 0;
    if(s>=e) return cnt;

    int mid = (s+e)/2;
    cnt += mergeSort(arr, s, mid);
    cnt += mergeSort(arr, mid+1, e);
    cnt += merge(arr, s, mid, e);
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int numConv = mergeSort(arr, 0, n-1);
    cout << numConv << endl;
    // for(int i=0; i<n; i++) cout << arr[i] << " ";
}
