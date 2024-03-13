#include <iostream>
#include <string>

using namespace std;

int getCollisions(int n, int m) {
    int collisions = m*(m+1)/2;
    if(n<m) {
        collisions = n*(n+1)/2 + (m-n)*n;
    }

    return collisions;
}

void bruteForce(string& a, string& b) {
    int n = a.length(), m = b.length();
    int collisions = getCollisions(n, m);

    int col = 0;
    for(int i=0; i<m; i++) {
        if(b[i] == 'T') {
            for(int j=min(i, n-1); j>=0; j--) {
                if(a[j] == 'T') {
                    col++;
                }
            }
        }
    }

    cout << col << " / " << collisions << endl;
}

void probabilityOfTruckCollision(string a, string b) {
    int n = a.length(), m = b.length();
    int totalCollisions = getCollisions(n, m);
    int truckCollisions = 0, truckCountsInA = 0;
    for(int i=0; i<m; i++) {
        if(i<n && a[i] == 'T') truckCountsInA++;
        if(b[i] == 'T') truckCollisions += truckCountsInA;
    }

    cout << truckCollisions << " / " << totalCollisions << endl;
}

int main() {
    string a, b;
    cin >> a >> b;

    probabilityOfTruckCollision(a, b);
    bruteForce(a, b);
}