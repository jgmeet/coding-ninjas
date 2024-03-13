/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 10^6
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/


#include <iostream>
using namespace std;
int mod = 1e9+7;

//DP
int balancedBTs(int h) {
	int* ans = new int[h+1];
	ans[0] = 1;
	ans[1] = 1;
	
	for(int i=2; i<=h; i++) {
		long x = ans[i-1];
		long y = ans[i-2];

		long hMinusOne = (x*x)%mod;
		long hMinusOneAndTwo = 2*(x*y)%mod;

		ans[i] = (hMinusOne+hMinusOneAndTwo)%mod;
	}
	
	return ans[h];
}

/**** Memoization
int balancedBTs(int h, int* ans) {
	// base case
	if(h<=1) return 1;

	// check if answer for h already exist
	if(ans[h]!=-1) return ans[h];

	long x = balancedBTs(h-1, ans)%mod;
	long y = balancedBTs(h-2, ans)%mod;

	// when both subtree height h-1, then total possible combinations
	long hMinusOne = (x*x)%mod;

	// when one subtree height h- 1 and another subtree height h-2, then total possible combinations
	long hMinusOneAndTwo = 2*(x*y)%mod;

	ans[h] = (hMinusOne+hMinusOneAndTwo)%mod;
	return ans[h];
}

int balancedBTs(int h) {
	int* ans = new int[h+1];
	for(int i=0; i<=h; i++) {
		ans[i] = -1;
	}

	return balancedBTs(h, ans);
}
****/

/**** Recursion
int balancedBTs(int h) {
	// base case
	if(h<=1) return 1;

	long x = balancedBTs(h-1)%mod;
	long y = balancedBTs(h-2)%mod;

	// when both subtree height h-1, then total possible combinations
	long hMinusOne = (x*x)%mod;

	// when one subtree height h- 1 and another subtree height h-2, then total possible combinations
	long hMinusOneAndTwo = 2*(x*y)%mod;

	return (hMinusOne+hMinusOneAndTwo)%mod;
}
****/

int main()
{
	int h;
	cin >> h;
	cout << balancedBTs(h);
}