/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/


#include <iostream>
#include <cmath>
using namespace std;

//DP
int minSquareCount(int n) {
    int* ans = new int[n+1];
    // base cases
    ans[0] = 0;
    ans[1] = 1;

    for(int i=2; i<=n; i++) { // i is acting as n when used in dp
        int count = INT_MAX;
        for(int j=1; j<=sqrt(i); j++) {
            int index = i-pow(j,2);
            /* Note: pow() gives number in double format, so convert the number to int if using it as index in array subscript */
            if(1+ans[index] < count) count = 1+ans[index];
        }
        ans[i] = count;
    }

    return ans[n];
}

/**** Memoization
int minSquareCount(int n, int* ans) {
    // base cases
    if(n<=0) return 0;
    if(n==1) return 1;

    // check if ans for n already exist
    if(ans[n]!=-1) return ans[n];

    int count = INT_MAX;
    for(int i=1; i<=sqrt(n); i++) {
        int localCount = 1+minSquareCount(n-pow(i,2), ans);
        if(localCount < count) count = localCount;
    }

    ans[n] = count; // save answer for n
    return ans[n];
}

int minSquareCount(int n) {
    int* ans = new int[n+1];
    for(int i=0; i<=n; i++) {
        ans[i] = -1;
    }

    return minSquareCount(n, ans);
}
****/

/**** Recursive approach
int minSquareCount(int n) {
    // base case
    if(n<=0) return 0;
    if(n==1) return 1;


    int ans = INT_MAX;
    for(int i=1; i<=sqrt(n); i++) {
        int count = 1+minSquareCount(n-pow(i,2));
        if(count < ans) ans = count;
    }

    return ans;
}
****/

int main() {

    int n;
    cin >> n;

    cout << minSquareCount(n);

}