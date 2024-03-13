#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& arr) {
    for(int i=1; i<arr.size(); i++) {
        int key = arr[i];
        int j=i;
        while(j>0) {
            if(key >= arr[j-1]) break;
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = key;
    }
}

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        bool flag = false;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }

        if(!flag) break;
    }
}

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        int ind = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[ind]) ind = j;
        }
        swap(arr[i], arr[ind]);
    }
}

int getInd(int start, int end, vector<int>& arr) {
    int pivot = arr[start];
    int i=start, j=end;

    while(i<j) {
        while(i<=end && arr[i] <= pivot) i++;
        while(j>=start && arr[j] > pivot) j--;
        if(i<j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[start], arr[j]);
    return j;
}

void quickSort(int start, int end, vector<int>& arr) {
    if(start >= end) return;

    int pivotInd = getInd(start, end, arr);
    quickSort(start, pivotInd-1, arr);
    quickSort(pivotInd+1, end, arr);
}

void quick_sort(vector<int>& arr) {
    int n = arr.size();
    quickSort(0, n-1, arr);
}

void print(vector<int>& arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

int main() {
    // int n;
    // cin >> n;
    vector<int> vec;
    while(true) {
        int num;
        cin >> num;
        if(num==-1) break;
        vec.push_back(num);
    }

    // insertion_sort(vec);
    // bubble_sort(vec);
    // selection_sort(vec);
    quick_sort(vec);
    print(vec);
}