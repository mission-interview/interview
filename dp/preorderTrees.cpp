#include<iostream>

using namespace std;

/**
 * Given a preorder sequence how many unique trees can be created
 * Solution is catalan number. Number of tree is exactly same
 * as number of unique BST create with array of size n (Assuming all numbers are different so nodes are different)
 * 
 * The way it works for preorder sequence is as follows
 * 
 * Suppose our preorder sequence is 1 2 3 4
 * So we need to compute following things
 * count(3)* 2 (combination of 2,3 and 4 on both side of 1)
 * count(1)*count(2) (combination of 2 on one side and 3, 4 on other side)
 * count(2)*count(1) (combinatino of 2,3 on one side and 4 on other side)
 * count(3)*2 can be broken into count(3)*count(0) + count(0)*count(3)
 * 
 * So our final result is
 * count(0)*count(3) + count(1)*count(2) + count(2)*count(1) + count(3)*count(0)
 * which is a catalan number
 *
 * So the actual sequence doesn't matter only the count. Note that a particular traversal is just a way of labeling the nodes in a tree, 
 * so that the number of possible binary trees is the same for any two traversals of the same length. The number of binary trees with n nodes is given by 
 * the n-1st Catalan number.  Catalan number Cn = (2n)!/(n+1)!*n!

 * Total number of possible Binary Search Trees with n different keys = Catalan number Cn = (2n)!/(n+1)!*n!
 * 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786....
 * Similarly, considering all the 5 nodes (2, 4, 6, 8 and 10). Possible number of Binary Tree are:
 * BT(5) = BT(0) * BT(4) + BT(1) * BT(3) + BT(2) * BT(2) + BT(3) * BT(1) + BT(4) * BT(0)
 * BT(5) = 1 * 14 + 1 * 5 + 2 * 2 + 5 * 1 + 14 * 1 = 42
 */

int TotalBTreeDP (int n) {
	if (n == 0) return 1;
	int dp[n+1];
	dp[0]=1; // Can clarify with interviewer but null is also a tree so 1 is fine
	dp[1]=1; // For one node only 1 tree possible
	for(int i = 2; i <= n; i++) {
		int sum = 0;
		for(int j = 0; j < i; j++) {
			sum += dp[j]*dp[i-j-1];
		}
		dp[i] = sum;
	}
	return dp[n];
}

int TotalBTreeRec (int n) {
	if (n == 0 || n == 1) {
		return 1;
	}

	int sum = 0;
  for (int i = 0; i < n; i++) {
  	sum += TotalBTreeRec(i) * TotalBTreeRec(n-i-1);
  }
  
  return sum;
}


int main() {
	cout << (TotalBTreeDP(5) == TotalBTreeRec(5)) << endl;
	cout << TotalBTreeDP(5) << endl;
	cout << (TotalBTreeDP(9) == TotalBTreeRec(9)) << endl;
	cout << TotalBTreeDP(9) << endl;
	return 0;
}

