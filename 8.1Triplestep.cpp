#include <vector>
#include <iostream>

using namespace std;

class Solution{
  int helper(int n, vector<int>& memo)
  {
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(memo[n]==0) 
      memo[n] = helper(n-3,memo) + helper(n-2,memo) + helper(n-1,memo);
    return memo[n];
  }
  int tripleStep(int n)
  {
    //all one step 1
    //all one step (n-2) +2
    //all one step (n-3)+3
    vector<int> memo(n+1,0);
    return helper(n,memo);
  };
}
