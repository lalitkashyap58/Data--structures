#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>> &matrix,int row,int col,vector<vector<int>> &dp)
    {
       if(col<0||col>=matrix[0].size())
           return 1e8;
        if(row==0) return matrix[0][col];
        
        if(dp[row][col]!=-1) return dp[row][col];
        int u=matrix[row][col]+solve(matrix,row-1,col,dp);
        int ur=matrix[row][col]+solve(matrix,row-1,col+1,dp);
        int ul=matrix[row][col]+solve(matrix,row-1,col-1,dp);
        
        
        
        return dp[row][col]=min(u,min(ur,ul));
           
        
        
        
        
    }
   int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int mini = INT_MAX;
        
        for(int i=0;i<n;i++)
            dp[0][i] = matrix[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini = INT_MAX;
                mini = min(mini, dp[i-1][j] + matrix[i][j]);
                if(j>=1)
                    mini = min(mini, dp[i-1][j-1] + matrix[i][j]);
                if(j<=n-2)
                    mini = min(mini, dp[i-1][j+1] + matrix[i][j]);
                dp[i][j] = mini;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans = min(ans, dp[n-1][i]);
        
        return ans;}
};