#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
   
public:
    bool check(vector<int>& nums) {
        int check=0;
        int n=nums.size();
        if(nums.size()==1)
        return true;
        
       
        for(int i=1;i<nums.size();i++)
        {if(nums[i-1]>nums[i])
        { if(nums[n-1]>nums[0])
        return false;
            check++;
        }

        }
        if(check>1)
        return false;
        return true;
    }
};