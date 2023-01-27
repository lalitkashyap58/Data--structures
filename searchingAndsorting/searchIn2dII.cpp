#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;
        int j=matrix[0].size()-1;
        while(i>=0&&i<matrix.size()&&j>=0&&j<matrix[0].size())
        {   int mid=(i+j)/2;
           if(matrix[i][j]==target)
         {return 1;
             
         }   
         if(matrix[i][j]>target)
            {
                j--;
            }
            else if(matrix[i][j]<target)
            {
                i++;
            }
       
        }
        return 0;
    }
};