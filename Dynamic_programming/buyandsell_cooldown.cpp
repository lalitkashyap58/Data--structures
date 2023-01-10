#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int index,vector<int> &prices,int buy,vector<vector<int>> &dp)
    {
        if(index>=prices.size())
        return 0;
       
       if(dp[index][buy]!=-1)
       return dp[index][buy];
   int profit=0;

       if(buy)
       {
           int notTake=solve(index+1,prices,1,dp);
           int take=0;
           take=-prices[index]+solve(index+1,prices,0,dp);
           profit=max(take,notTake);
           dp[index][buy]=profit;
       }
       else
       {       int notSell=solve(index+1,prices,0,dp);
       int sell=0;
       
      sell= prices[index]+solve(index+2,prices,1,dp);
       dp[index][buy]=max(notSell,sell);
       }
       return dp[index][buy];
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2,vector<int> (2,0));
    //vector<int> check(prices.size(),0);
    //base case
    for(int index=prices.size()-1;index>=0;index--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit=0;

       if(buy)
       {
           int notTake=dp[index+1][1];
           int take=0;
           take=-prices[index]+dp[index+1][0];
           profit=max(take,notTake);
           dp[index][buy]=profit;
       }
       else
       {       int notSell=dp[index+1][0];
       int sell=0;
       
      sell=prices[index]+dp[index+2][1];
       dp[index][buy]=max(notSell,sell);
       }
       
        }
    }
    return dp[0][1];
    }
};