/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
274
*/


#include <iostream>
#include <climits>
using namespace std;
long long m = 1e9 + 7;

int main() {

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;

        int* ans = new int[n+1];
        ans[0] = 1; // step already taken, storing it's effect for ans[0]=1
        ans[1] = 1; // 1 step can be taken in only 1 way
        ans[2] = 2; // (1,1) , (2)
        ans[3] = 4; // (1,1,1) , (1,2), (2,1)

        for (int i = 4; i <= n; i++) {
        int oneStep = ans[i - 1];
        int twoSteps = ans[i - 2];
        int threeSteps = ans[i - 3];
        ans[i] = ((oneStep % m) + (twoSteps % m) + (threeSteps % m)) % m;
        }

        cout << ans[n] << endl;
        delete [] ans;
    }
}