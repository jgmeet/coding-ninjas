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
        delete next;
    }
};

template <typename T>
class queue {

    Node<T> *head;
    Node<T> *tail;
    int len;

    public:

    queue() {
        head=NULL;
        tail=NULL;
        len=0;
    }

    // get size of queue
    int size() {
        return len;
    }

    // check if queue is empty
    bool isEmpty() {
        return len==0;
    }

    // insert new element
    void push(T element) {
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        len++;
    }

    // get front element
    T front() {
        if(head == NULL) {
            cout << "queue empty" << endl;
            return 0;
        }

        return head->val;
    }

    // get last element
    T back() {
        if(tail == NULL) {
            cout << "queue empty" << endl;
            return 0;
        }

        return tail->val;
    }

    // remove element
    void pop() {
        if(head == NULL) {
            cout << "queue empty" << endl;
        }
        else {
            Node<T> *tmp = head;
            head = head->next;
            tmp->next = NULL;
            delete tmp;
        }
        len--;
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
