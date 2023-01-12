#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int maxi=1;
        int lastIndex=0;
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size(),0);
       for(int i=1;i<nums.size();i++)
       {   hash[i]=i;//making alias array according to index
           for(int j=0;j<i;j++)
           {
               if(nums[i]%nums[j]==0&&dp[j]+1>dp[i])
               {
                   dp[i]=dp[j]+1;
                   hash[i]=j;
               }
              
           }
            if(dp[i]>maxi)
               {
                   maxi=dp[i];
                   lastIndex=i;
               }
          

       }
        vector<int> temp;
           temp.push_back(nums[lastIndex]);
           //this technique to get the answer important technique
           while(hash[lastIndex]!=lastIndex)
           {
               lastIndex=hash[lastIndex];
               temp.push_back(nums[lastIndex]);
           }
           reverse(temp.begin(),temp.end());
           return temp;
    
        
    }
};