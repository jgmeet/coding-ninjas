#include <iostream>
using namespace std;

int main() {
    int a1 = 10;
    int a2 = 20;
    int *p1 = &a1;
    int *p2 = &a2;
    cout << a1 << ", " << a2 << endl;
    cout << ++(*p1) << ", " << (*p2)++ << endl;
    cout << *p1 << ", " << *p2 << endl;
    cout << "size of p2: " << sizeof(p2) << "\n";
}