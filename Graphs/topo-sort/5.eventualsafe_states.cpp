#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
    private:
    bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[],int check[]) {
      vis[node] = 1;
      dfsVis[node] = 1;
      check[node]=0;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis,check)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      check[node]=1;
      dfsVis[node] = 0;
      return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
         int vis[V]={0};
         int dfsVis[V]={0};
         int check[V]={0};
     
    vector<int> safeNodes;

      for (int i = 0; i < V; i++) {
        if (!vis[i]) {
          // cout << i << endl; 
          checkCycle(i, adj, vis, dfsVis,check); 
             // cout << i << endl;
             }
      }
      for(int i=0;i<V;i++)
      {
          if(check[i]==1)
          safeNodes.push_back(i);
      }
        
        
        return safeNodes;
        
    }
};