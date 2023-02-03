#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0],res = nums[0];
		for(int i=1;i<nums.size();i++)
		{
	maxi = max(maxi + nums[i],nums[i]);  // choosing if adding current element to previous max will further maxify or not
			res = max(res,maxi);  // choosing the maximum subarray answers
		}
		 return res;
    }
};