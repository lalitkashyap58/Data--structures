//User function template for C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    int func(int *arr,int index,vector<int> &dp)
    {  
        if(index==0)
        return arr[0];
        if(index<0)
        return 0;
        
        if(dp[index]!=-1)
        return dp[index];//memoisation base case to resolve overlapping subperoblems handle 
    
        int pick=arr[index]+func(arr,index-2,dp);
        int notpick=func(arr,index-1,dp);
        dp[index]= max(pick,notpick);
        return dp[index];
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	     dp[0]=arr[0];//base case
	    int neg=0;//base case for negative
	    for(int i=1;i<n;i++)
	    {
	         int pick=arr[i];
	         if(i>1)
	         pick+=dp[i-2];
        int notpick=dp[i-1];
        
        dp[i]= max(pick,notpick);
	        
	    }
	    
	    return dp[n-1];
	    
	    
	    
	}
};