#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>> &grid,int m,int n,vector<vector<int>> &dp)
{
    int row=grid.size();
    int col=grid[0].size();
    
     if(m==row-1&&n==col-1)
     return grid[m][n];

     if(m>=row||n>=col)
     return 1000;
     if(dp[m][n]!=-1)
     return dp[m][n];
   
         int down=grid[m][n]+ solve(grid,m+1,n,dp);
         int right =grid[m][n]+  solve(grid,m,n+1,dp);
    dp[m][n]=min(down,right);
    return  dp[m][n];
} 
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                if(i==row-1&&j==col-1)
                    dp[i][j]=grid[i][j];
                else
                {
                   int down=grid[i][j];
                    if(i<row-1)
                        down+=dp[i+1][j];
                    else
                        down+=1e9;
         int right =grid[i][j];
                    if(j<col-1)
                       right+=dp[i][j+1];
                    else
                        right+=1e9;
                dp[i][j]=min(right,down);
            }}
        }
        return dp[0][0];
    }
};