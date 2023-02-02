//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int maxi=INT_MIN;
	    int ans=-1;
	    for(int row=0;row<n;row++)
	    {   if(ans==n)
	          return ans;
	        for(int col=0;col<m;col++)
	    {   
	        if(arr[row][col]==0&&maxi>m-col)
	        {
	            break;
	        }
	        
	        if(arr[row][col]==1)
	        {   if(maxi<m-col)
	        {
	            maxi=m-col;
	            ans=row;
	            break;
	        }
	            
	            
	        }
	    }
	        
	    }
	    return ans;
	    
	    // code here
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends