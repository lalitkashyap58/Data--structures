//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findTheNumbersBefore(vector<int> &nums, int target) {

        int lo = 0, hi = nums.size()-1, mid;

        

        while(lo <= hi) {

            mid = (lo + hi) >> 1;

            if(nums[mid] <= target) {

                lo = mid+1;

            } else {

                hi = mid-1;

            }

        }

        

        return lo;

    }

    

    int median(vector<vector<int>> &matrix, int R, int C){

        int lo = 1, hi = 2000, mid;

        int ind = (R*C)/2;

        

        while(lo <= hi) {

            mid = hi + (lo - hi)/2;

            int sum = 0;

            

            for(int i = 0; i < R; i++) {

                sum += findTheNumbersBefore(matrix[i], mid);

            }

            

            if(sum > ind) hi = mid-1;

            else lo = mid+1;

        }
    }

        
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends