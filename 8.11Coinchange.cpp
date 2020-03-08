#include<iostream>
#include<algorithm>
#include<vector>

class Solution{
  public : 
   int coinChange(vector<int>& coins, int amount) 
   {
     int max = amount+1;
     vector<int> dp(max,max);
     for(int i = 1; i<=amount;i++)
     {
       for(int j = 0; j<coins.size();j++)
       {
         if(coins[j]<=i)
           dp[i] = min(dp[i],dp[i-coins[j]]+1);
       }
     }
     return dp[amount]>amount? -1 : dp[amount];
   }
};
