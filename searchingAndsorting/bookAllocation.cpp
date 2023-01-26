//User function template in C++

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution 
{ private:
 bool possible(int arr[],int N,int M, int mid)
 {int st=1;
 int sum=0;
 for(int i=0;i<N;i++)
 {
     sum+=arr[i];
     if(sum>mid)
     {
         st++;
         sum=arr[i];
     }
 }
     return st<=M;
 }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {int sum=0;
    int maxi=0;
    if(M>N)
    return -1;
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
        maxi=max(maxi,A[i]);
    }
    int low=maxi;
    int high=sum;
    int ans=0;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        
        if(possible(A,N,M,mid)==true)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
        //code here
    }
};