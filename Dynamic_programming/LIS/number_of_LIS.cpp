#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int solve(vector<int> &nums)
{
     vector<int> dp1(nums.size()+1,1) ,cnt(nums.size()+1,1);
     int maxi=1;
     int lastIndex=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[i]>nums[j]&&dp1[i]<dp1[j]+1)
                {
                    dp1[i]=dp1[j]+1;
                    //inherit
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i]&&dp1[i]==dp1[j]+1)
                {
                    cnt[i]=cnt[i]+cnt[j];//increase the cnt
            }
            }
            
                     if(dp1[i]>maxi)
            {
                maxi=dp1[i];
                lastIndex=i;
            }
           
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {   cout<<cnt[i]<<endl;
            if(dp1[i]==maxi)
            {
                ans+=cnt[i];
            }
        }

        return ans;
}
    int findNumberOfLIS(vector<int>& nums) {
        return solve(nums);
    }
};