//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    bool solve(vector<int> arr, int sum, int index,vector<vector<int>> &dp)
    {if(index==0)
    {
        
        if(arr[index]-sum==0)
        return true;
        else
         return false;
    }
    if(dp[index][sum]!=-1)
    return dp[index][sum];

    if(sum==0)
    return true;
    bool taken =false;
    if(sum>=arr[index])
       taken=solve(arr,sum-arr[index],index-1,dp);
    
      bool notTaken=solve(arr,sum,index-1,dp);
      dp[index][sum]=taken ||notTaken;
      return dp[index][sum];
    
       
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,false));
         for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
     if(arr[0]<=sum)
        dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=sum; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][sum];
    
    
    
    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends