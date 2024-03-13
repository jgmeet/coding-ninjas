#include <iostream>
using namespace std;

template <typename T>
class stack{
    // private data, as we don;t want direct access to user
    T *data;
    int nextIndex;
    int capacity;

    public:

    stack() {
        data = new T[1];
        nextIndex=0;
        capacity=1;
    }

    // returm number of elements present in the stack
    int size() {
        return nextIndex;
    }

    // return true if stack empty else return false
    bool isEmpty() {
        return nextIndex == 0;
    }

    // insert element into stack
    void push(T element) {
        if(nextIndex == capacity) {
            T *newData = new T[2*capacity];
            for(int i=0; i<capacity; i++) newData[i] = data[i];
            delete [] data;
            data = newData;
            capacity *= 2;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    // get top element of stack
    T top() {
        if(isEmpty()) {
            cout << "stack empty" << endl;
            return -1;
        }
        return data[nextIndex-1];
    }

    // deletes topmost element in stack and returns it
    T pop() {
        if(isEmpty()) {
            cout << "stack empty" << endl;
        }
        nextIndex--;
        return data[nextIndex];
    }

};

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    
    cout << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    st.pop();
    cout << st.size() << endl;
    cout << st.top() << endl;
    st.pop();
    st.pop();
    st.top();
}