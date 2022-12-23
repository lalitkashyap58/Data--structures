#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool check(int start,int V, vector<int> adj[],int color[])
    {
        // Code here
	   
	    queue<int> q;
	    q.push(start);
	    
	   color[start]=0;
	   
	   while(!q.empty())
	   { int node=q.front();
	   q.pop();
	      for(auto it:adj[node])
	       {
	           if(color[it]==-1)
	           {
	           color[it]=!color[node];
	           q.push(it);
	           
	           }
	           else if (color[it]==color[node])
	           {
	               return false;
	           }
	       }
	   }
	   
	  	return true;
    }
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int colors[V];
	    for(int i=0;i<V;i++)
	    {colors[i]=-1;
	    
	        
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(colors[i]==-1)
	        {
	            if(check(i,V,adj,colors)==false)
	            return false;
	            
	        }
	    }
	    
 return true;
	}

};