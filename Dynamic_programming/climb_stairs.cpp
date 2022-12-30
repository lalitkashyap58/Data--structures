#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// int solve(int index,int &count,vector<int> &dp)
//     { if(index<0)
//     {
//         return 0;
//     }else
//         if(index==0)
//         {  
//             return 1;
//         }
//     if(dp[index]!=-1) return dp[index];// this line is important for memoisation 2.
     
//     int left= solve(index-1,count,dp);
//     int right=solve(index-2,count,dp);
//      return dp[index]=left+right;//ye logic important tha for applying dp 3.
     
     
        
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
       
//         int count=0;
//         return solve(n,count,dp);
       
        
        
//     }
   
    
class Solution {
    public:
     int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};