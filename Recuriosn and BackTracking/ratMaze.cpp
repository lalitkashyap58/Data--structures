//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{

    public:

    vector<string> ans;

void  fun(int i , int j , int n , vector<vector<int>> m , vector<vector<bool>>&vis , string s){

         if(i<0 || j<0 || i>=n || j>=n||m[i][j]==0||vis[i][j]==1)return ;

        if(i==n-1&&j==n-1){ ans.push_back(s);return;}

        vis[i][j]=1;

        fun(i+1,j,n,m,vis ,s+'D');

        fun(i,j-1,n,m,vis ,s+'L');

        fun(i-1,j,n,m,vis ,s+'U');

        fun(i,j+1,n,m,vis ,s+'R');

        vis[i][j]=0; }

 

    vector<string> findPath(vector<vector<int>> &m, int n) {

        vector<vector<bool>>vis(n , vector<bool>(n,0));

        string s="";

        fun( 0,0,n,m,vis , s);

        return ans;

       

    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends