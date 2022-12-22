//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs(int row,int col,int n,int m,vector<vector<int>> &vis,vector<vector<char>> mat,vector<vector<char>> &ans)
{
    
    vis[row][col]=1;
    int r[]={-1,+1,0,0};
    int c[]={0,0,-1,+1};
   for(int i=0;i<4;i++)
    {
        int delrow=row+r[i];
        int delcol=col+c[i];
        if(delrow>=0&&delrow<n&&delcol>=0&&delcol<m&&!vis[delrow][delcol]&&mat[delrow][delcol]=='O')
        {
            dfs(delrow,delcol,n,m,vis,mat,ans);
           
            
        }
    }
    
    
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<char>> ans(n,vector<char>(m,'O'));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {    
                if((i==0||j==0||i==n-1||j==m-1)&&!vis[i][j])
                {
                    if(mat[i][j]=='O')
                    {   
                        dfs(i,j,n,m,vis,mat,ans);
                        
                    }
                    else
                    {   vis[i][j]=1;
                        ans[i][j]='X';
                    }
                }
                
                    
                
            }
        }
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {    
                if(!vis[i][j])
                {
                    ans[i][j]='X';
                }
                
                    
                
            }
        }
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends