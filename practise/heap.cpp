#include <iostream>
using namespace std;

class heap {
    vector<int> arr;
    int size;

    public:

    heap() {
        size=0;
    }

    void insert(int val) {
        arr.push_back(val);
        size++;

        int ind = size-1;
        while(ind>0) {
            int paretnInd = (ind-1)/2;
            if(arr[ind] > arr[paretnInd]) {
                swap(arr[ind], arr[paretnInd]);
                ind = paretnInd;
            }
            else return;
        }
    }

    void del() {
        arr[0] = arr[size-1];
        size--;

        int ind = 0;
        int leftChildInd = 2*ind+1;
        int rightChildInd = 2*ind+2;
        while(rightChildInd < size) {
            if(arr[ind] < arr[leftChildInd] && arr[leftChildInd] >= arr[rightChildInd]) {
                swap(arr[ind], arr[leftChildInd]);
                ind = leftChildInd;
            }
            else if(arr[ind] < arr[rightChildInd] && arr[rightChildInd] >= arr[leftChildInd]) {
                swap(arr[ind], arr[rightChildInd]);
                ind = rightChildInd;
            }

            leftChildInd = 2*ind+1;
            rightChildInd = 2*ind+2;
        }

        if(leftChildInd < size && arr[ind] < arr[leftChildInd]) {
            swap(arr[ind], arr[leftChildInd]);
        }
    }

    void print() {
        for(int i=0; i<size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

void heapify(int arr[], int n, int ind) {
    int parent = ind;
    int left = parent*2+1;
    int right = parent*2+2;
    while(right < n) {
        if(arr[parent] < arr[left] && arr[left] >= arr[right]) {
            swap(arr[parent], arr[left]);
            parent = left;
        }
        else if(arr[parent] < arr[right] && arr[right] >= arr[left]) {
            swap(arr[parent], arr[right]);
            parent = right;
        }
        else break;

        left = parent*2+1;
        right = parent*2+2;
    }

    if(left < n && arr[parent] < arr[left]) swap(arr[left], arr[parent]);
}

void heap_sort(int arr[], int n) {
    // heapify
    for(int i=n-1; i>=0; i--) heapify(arr, n, i);

    for(int i=n-1; i>0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    /*
    heap hp;
    hp.insert(10);
    hp.insert(20);
    hp.insert(18);
    hp.insert(13);
    hp.insert(10);

    hp.print();
    hp.del();
    hp.print();
    */

    int arr[] = {2,35,353,2,452,2,532,1};
    // for(int i=7; i>=0; i--)  heapify(arr, 8, i);

    heap_sort(arr, 8);
    for(int i=0; i<8; i++) cout << arr[i] << " ";
    cout << endl;
}