#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int func(vector<int> &height,int n,vector<int> &dp)
  {
      if(n==0)
      return 0;
      if(dp[n]!=-1)
      return dp[n];
      int step1=func(height,n-1,dp)+abs(height[n]-height[n-1]);
        int step2=INT_MAX;
      if(n>1)
       step2=func(height,n-2,dp)+abs(height[n]-height[n-2]);
      dp[n]=min(step1,step2);
      return dp[n];
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        func(height,n-1,dp);
        return dp[n-1];
         
    }
};