#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
    
    T val;
    Node<T> *next;
    
    Node(T val) {
        this->val = val;
        next = NULL;
    }
    
    ~Node() {
        delete this->next;
    }
};

template <typename T>
class stack {
    // private data
    Node<T> *head, *tail;
    int len;

    public:

    stack() {
        head=NULL, tail=NULL;
        len=0;
    }

    // returm number of elements present in the stack
    int size() {
        return len;
    }

    // return true if stack empty else return false
    bool isEmpty() {
        return len == 0;
    }

    // insert element into stack
    void push(T element) {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        if(tail == NULL) tail = newNode;
        len++;
    }

    // get top element of stack
    T top() {
        if(head == NULL) {
            cout << "stack empty" << endl;
            return -1;
        }
        return head->val;
    }

    // deletes topmost element in stack and returns it
    void pop() {
        if(head == NULL) cout << "stack empty" << endl;
        else {
            head = head->next;
            len--;
        }
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
    cout << st.top() << endl;
}