// User function Template for C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int dfs(int i,int j,vector<vector<int>> &A){
        if( i<0 || j<0 || i>=A.size() || j>=A[0].size() || A[i][j]==0)
            return 0;
        
        A[i][j] = 0;
        
        return 1+dfs(i-1,j,A)+dfs(i+1,j,A)+dfs(i,j-1,A)+dfs(i,j+1,A);
    }
    
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int all_one=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                    all_one+=grid[i][j];
        }
        int close_one = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if((i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1) && grid[i][j]==1)
                    close_one+= dfs(i,j,grid);
            }
        }
        return all_one - close_one;
    }
};