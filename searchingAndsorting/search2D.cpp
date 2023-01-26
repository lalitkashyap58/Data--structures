#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowNum=matrix.size();
        int colNum=matrix[0].size();
        int mid;
        int begin=0;
        int end=rowNum*colNum-1;
        while(begin<=end)
        {mid=begin+(end-begin)/2;
         
         int mid_val=matrix[mid/colNum][mid%colNum];//crucial step is here
         if(mid_val==target)
             return true;
         
         if(mid_val<target)
         {
          begin=mid+1;
            
         }
         else{
         end=mid-1;
         }
            
        }
        return false;
        
    }
};