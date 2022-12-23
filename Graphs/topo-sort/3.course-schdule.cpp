#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool isPossible(int V, vector<pair<int, int> >& prerequisites)
	{  vector<int> adj[V];//adjanceny list to form the graph
	
	for(auto it:prerequisites)
	{
	    adj[it.first].push_back(it.second);
	    
	}
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    vector<int> topo;
	    
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        //node is in your topo sort ,you can reduce indegree
	        for(auto it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	        
	    }
	    if(topo.size()==V)
	    return true;
	    
	    return false;
	    
	    
	    
	}
};