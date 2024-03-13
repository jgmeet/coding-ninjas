#include <iostream>
using namespace std;

template <typename T>
class queue {

    T *data;
    int first; // for storing index of first element inserted in queue
    int last;  // for storing index of last element inserted in queue
    int capacity;
    
    public:

    queue() {
        data = new T[1];
        first = 0, last = 0;
        capacity = 1;
    }

    // getting size of quque
    int size() {
        return last-first;
    }

    // check if queue is empty
    bool isEmpty() {
        return last == first;
    }

    // insert element in queue
    void push(T element) {
        if(last == capacity) {
            T *newData = new T[2*capacity];
            for(int i=first; i<capacity; i++) {
                newData[i-first] = data[i];
            }
            first = 0, last = capacity;
            capacity *= 2;
            data = newData;
        }

        data[last] = element;
        last++;
    }

    // get front element i.e. element inserted at first in queue
    T front() {
        if(first == last) {
            cout << "queue empty";
            return 0;
        }
        
        return data[first];
    }

    // get last element i.e. element inserted at last in queue
    T back() {
        if(first == last) {
            cout << "queue empty";
            return -1;
        }
        
        return data[last-1];
    }

    // to delete the first element or to pop out first element of queue
    void pop() {
        if(first == last) {
            cout << "queue empty";
            return;
        }

        first++;
    }

};

int main() {
    queue<int> q;
    q.push(3);
    q.push(8);
    q.push(4);
    q.push(7);
    q.push(1);

    cout << q.size() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.back();
}