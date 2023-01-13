#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//{ Driver Code Starts


// } Driver Code Ends
class Solution{
    int solve(vector<int> &nums)
    {  
    
        vector<int> dp1(nums.size()+1,1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[i]>nums[j]&&dp1[i]<dp1[j]+1)
                {
                    dp1[i]=dp1[j]+1;
                }
            }
           
        }
         vector<int> dp2(nums.size()+1,1);
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=nums.size()-1;j>i;j--)
            {
                if(nums[i]>nums[j]&&dp2[i]<dp2[j]+1)
                {
                    dp2[i]=dp2[j]+1;
                }
            }
           
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    
    }
	public:
	int LongestBitonicSequence(vector<int>nums)
	{    int ans=solve(nums);
        return ans;
	    // code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends