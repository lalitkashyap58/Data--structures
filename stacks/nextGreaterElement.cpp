#include<iostream>
#include<stdio.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         stack<int> st;
        unordered_map<int,int> umap;
        vector<int> res(nums1.size(),-1);
        for(int i=0;i<nums2.size();i++)
        {
            int element=nums2[i];
            while(!st.empty()&&element>st.top())
            {
                umap[st.top()]=element;
                st.pop();
            }
            st.push(element);
        }
        for(int j=0;j<nums1.size();j++)
        {  int ele=nums1[j];
            if(umap.find(ele)!=umap.end())
            {
              int nge = umap[ele];
                res[j] = nge;
            }
        }
        
        
        
        return res;
    }
};
