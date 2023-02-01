#include <bits/stdc++.h>

using namespace std;
class Solution {

public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int snowballsize=0;
        for(int i =0;i<n;i++){
            if(nums[i]==0) snowballsize++;
            else{
                int temp=nums[i];
                nums[i]=0;
                nums[i-snowballsize]=temp;
            }
        }
       


    }
};