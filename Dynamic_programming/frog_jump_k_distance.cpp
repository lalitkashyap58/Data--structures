#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
//     int func(vector<int> &height,int n,int k,vector<int> &dp)
//     {
//         if(n==0)
//         return 0;
//         if(dp[n]!=-1)
//         return dp[n];
//         int min_steps=INT_MAX;
//         for(int i=1;i<=k;i++)
//         {   if(n-i>=0)
//               {int jump=func(height,n-i,k,dp)+abs(height[n]-height[n-i]);
//              min_steps=min(min_steps,jump);
//              dp[n]=min_steps;
//               }
            
//         }
//         return dp[n];
//     }
//   public:
//     int minimizeCost(vector<int>& height, int n, int k) {
//         // Code here
//         vector<int> dp(n,-1);
//         return func(height,n-1,k,dp);
        
        
        
        
//     }
// };
class Solution {
    int func(vector<int> &height,int n,int k,vector<int> &dp)
    {
        if(n==0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int min_steps=INT_MAX;
        for(int i=1;i<=k;i++)
        {   if(n-i>=0)
              {int jump=func(height,n-i,k,dp)+abs(height[n]-height[n-i]);
             min_steps=min(min_steps,jump);
             dp[n]=min_steps;
              }
            
        }
        return dp[n];
    }
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n,-1);
         dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends