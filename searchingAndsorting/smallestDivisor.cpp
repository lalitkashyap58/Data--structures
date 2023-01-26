#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(nums[i],maxi);
        }
        int low=1;
        long long int sum;
        int mid;
        int ans=INT_MAX;
        while(low<=maxi)
        {sum=0;
         mid=(low+maxi)/2; 
         cout<<"low  :"<<low<<"  maxi:"<<maxi<<"mid :"<<mid<<endl;
            for(int i=0;i<nums.size();i++)
            {    if(mid>0)
            {sum+=nums[i]/mid;
                if(nums[i]%mid!=0)
                    sum++;
            
            }
            }
         if(sum>threshold)
         {
             low=mid+1;
         }
         else
         {  ans=mid;
             maxi=mid-1;
         } 
        
        
         
         cout<<sum<<endl;
        }
           return ans;
    }
};