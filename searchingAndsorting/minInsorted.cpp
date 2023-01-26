 
 #include<iostream>
 #include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int>& nums) {
         int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (nums[mi] > nums[hi]) { 
                lo = mi + 1;
            }
            else if (nums[mi] < nums[lo]) { 
                hi = mi;
                
            }
            else { // nums[lo] <= nums[mi] <= nums[hi] 
                hi--;
            }
        }
        
        return nums[lo];
    }
};