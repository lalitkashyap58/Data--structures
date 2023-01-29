#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void subarrays(int index,vector<int> &candidates,int target,vector<int> &ans,vector<vector<int>> &final_ans)
    {
        if(index==candidates.size())
        {if(target==0)
        final_ans.push_back(ans);
          return;
        }
    
    if(candidates[index]<=target)
    {
     //including   
     ans.push_back(candidates[index]);
        subarrays(index,candidates,target-candidates[index],ans,final_ans);
    
     ans.pop_back();
        }//removing the element
     //not including
        subarrays(index+1,candidates,target,ans,final_ans);
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> final_ans;
        subarrays(0,candidates,target,ans,final_ans);
        return final_ans;
    }
};