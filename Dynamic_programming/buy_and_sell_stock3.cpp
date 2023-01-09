#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int solve(vector<int> &prices,int index,int buy,int count,vector<vector<vector<int>>> &dp)
    {
        if(index==prices.size()||count==0)
        return 0;
        if(dp[index][buy][count]!=-1)
        return dp[index][buy][count];
        int profit=0;
     if(buy==1)
     {
          return dp[index][buy][count]=max(-prices[index]+solve(prices,index+1,0,count,dp),solve(prices,index+1,1,count,dp));
     }
      
          return dp[index][buy][count]=max(prices[index]+solve(prices,index+1,1,count-1,dp),solve(prices,index+1,0,count,dp));
     
     
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int count=2;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cap=1;cap<=2;cap++)
                {
                    if(buy==1)
     {
           dp[index][buy][cap]=max(-prices[index]+dp[index+1][0][cap],dp[index+1][1][cap]);
     }
        else
        {
          dp[index][buy][cap]=max(+prices[index]+dp[index+1][1][cap-1],dp[index+1][0][cap]);
        }
                }
            }
        }
        
        return dp[0][1][2];
        
    }
};