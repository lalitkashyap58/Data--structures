
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//     int solve(vector<int> &nums,int index,int amount,vector<vector<int>> &dp)
//     { if(index==0)
//     {
//         if(amount%nums[index]==0)
//             return amount/nums[index];//base cases are important so write them on your own
//         else
//             return INT_MAX;
//     }
         
//        if(dp[index][amount]!=-1) return dp[index][amount];
        
//         int notTake=solve(nums,index-1,amount,dp);
//         int take=INT_MAX;
//         if(amount>=nums[index])
//         take=1+solve(nums,index,amount-nums[index],dp);
//         return dp[index][amount]= min(take,notTake);
//     }
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<amount+1;i++)
        {
            if(i%coins[0]==0)
                dp[0][i]=i/coins[0];
        else
            dp[0][i]=1e9;
        }
        
        for(int ind = 1; ind<n; ind++){
        for(int target = 0; target<=amount; target++){
            
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(coins[ind]<=target)
                take = 1 + dp[ind][target - coins[ind]];
                
             dp[ind][target] = min(notTake, take);
        }
    }
    
    int ans = dp[n-1][amount];
    if(ans >=1e9) return -1;
    return ans;
      
    }
};