#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int solve(int index1,int index2,string s1,string s2)
    {
        if(index1<0||index2<0)
        return 0;




        if(s1[index1]==s2[index2])
        return 1+solve(index1-1,index2-1,s1,s2);

        if((s1[index1]!=s2[index2]))
        return 0+ max(solve(index1-1,index2,s1,s2),solve(index1,index2-1,s1,s2));

        return 0;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
  int n=text1.size();
  int m=text2.size();
  vector<vector<int>> dp(n+1,vector<int>(m+1,0));

  //base case
  string s1=text1;
  string s2=text2;
  


  for(int index1=1;index1<=n;index1++)
  {
      for(int index2=1;index2<=m;index2++)
      {
            if(s1[index1-1]==s2[index2-1])
        dp[index1][index2]= 1+dp[index1-1][index2-1];

        if((s1[index1-1]!=s2[index2-1]))
        dp[index1][index2]= 0+ max(dp[index1-1][index2],dp[index1][index2-1]);


      }
  }

  return dp[n][m];
        
    }
};