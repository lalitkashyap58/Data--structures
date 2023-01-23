#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstOccurence(vector<int> &nums,int target)
    {
        int low=0;
         int high=nums.size()-1;
        int res=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
           if(nums[mid]==target)
           {
               res=mid;
               high=mid-1;
           }
            else if(nums[mid]>target)
                high=mid-1;
             else
                low=mid+1;
                
        }
        return res;
    }
    int lastOccurence(vector<int> &nums,int target)
    {
        int low=0;
         int high=nums.size()-1;
        int res=-1;
        while(low<=high)
        {
          int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> finalAns(2,0);
        finalAns[0]=firstOccurence(nums,target);
        finalAns[1]=lastOccurence(nums,target);
        return finalAns;
        
    }
};