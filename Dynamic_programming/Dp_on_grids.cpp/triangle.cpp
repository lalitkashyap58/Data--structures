#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int maxRow=triangle.size();
        int n=triangle[maxRow-1].size();
        vector<vector<int>> dp(maxRow,vector<int>(n));
        for(int j=0;j<n;j++)
        {
            dp[maxRow-1][j]=triangle[maxRow-1][j];
        }
        for(int i=maxRow-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                dp[i][j]=min(dp[i+1][j+1],dp[i+1][j])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};