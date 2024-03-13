/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 10 ^ 6
Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  
*/


#include <iostream>
#include <climits>
using namespace std;

/**** DP ****/
int minStepsTo1(int n) {
    int* ans = new int[n+1];
    ans[0]=0, ans[1]=0;  // no steps needed for n<=1


    for(int i=2; i<=n; i++) {
        int subtractOne = ans[i-1];
        int divideByTwo = INT_MAX;
        int divideByThree = INT_MAX;
        if(i%2 == 0) divideByTwo = ans[i/2];
        if(i%3 == 0) divideByThree = ans[i/3];

        ans[i] = 1+min(subtractOne, min(divideByTwo, divideByThree));
    }

    return ans[n];
}

/**** Memoization Approach
int minStepsTo1(int* ans, int n) {
    if(n==1) return 0; // n is already reduced to 1, no futher step needed

    if(ans[n]!=-1) {  // check if ans for n already exist i.e. calculated
        return ans[n];
    }

    int subtractOne = minStepsTo1(ans, n-1);
    int divideByTwo = INT_MAX;
    int divideByThree = INT_MAX;

    if(n%2 == 0) divideByTwo = minStepsTo1(ans, n/2);
    if(n%3 == 0) divideByThree = minStepsTo1(ans, n/3);

    ans[n] = 1+min(subtractOne, min(divideByTwo, divideByThree)); // save the answer in array for index n

    return ans[n];
}

int minStepsTo1(int n) {
    int* ans = new int[n+1];
    for(int i=0; i<=n; i++) {
        ans[i] = -1;
    }

    return minStepsTo1(ans, n);
}
****/

/**** Recursive approach
int minStepsTo1(int n) {
    if(n==1) return 0; // n is already reduced to 1, no futher step needed

    int x, y = INT_MAX, z = INT_MAX;
    x = minStepsTo1(n-1);
    if(n%2 == 0) y = minStepsTo1(n/2);
    if(n%3 == 0) z = minStepsTo1(n/3);

    return 1+min(x, min(y,z));
}
*****/

int main() {
    int n;
    cin >> n;

    cout << minStepsTo1(n);
}