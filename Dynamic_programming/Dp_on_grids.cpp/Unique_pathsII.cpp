#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  
      int uniquepaths(vector<vector<int>> &obstacleGrid,int currRow,int currCol,vector<vector<int>> &dp)
{  int row=obstacleGrid.size();
 int col=obstacleGrid[0].size();
 if(currRow>row-1||currCol>col-1||obstacleGrid[currRow][currCol]==1)
    return 0;
    if(currRow==row-1&&currCol==col-1 )
    {
        
        return 1;
    }
    
   if( dp[currRow][currCol]!=-1)
   return dp[currRow][currCol];
    int down=uniquepaths(obstacleGrid,currRow+1,currCol,dp);
    int right=uniquepaths(obstacleGrid,currRow,currCol+1,dp);
    return dp[currRow][currCol]= right + down;
    
}
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int row=obstacleGrid.size();
 int col=obstacleGrid[0].size();
        int dp[row][col];
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else if(i==0&&j==0)
                    dp[i][j]=1;
                else
                {
                    int up=0;
                    int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0)  left=dp[i][j-1];
                    
                    dp[i][j]=up+left;
                        
                    
                }
            }
        }
        return dp[row-1][col-1];
        
    }
    
};