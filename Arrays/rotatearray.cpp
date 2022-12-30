#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    class Solution 
    {
    public:
        void rotate(vector<int>&nums, int k) 
        {   int n=nums.size();
            k = k%n;
    
            // Reverse the first n - k numbers.
            // Index i (0 <= i < n - k) becomes n - k - i.
            int *p1=&nums[0];
            int *p2=&nums[n-k];
            reverse(p1, p2);
            
            // Reverse tha last k numbers.
            // Index n - k + i (0 <= i < k) becomes n - i.
             reverse(p2, &nums[n]);
            
            // Reverse all the numbers.
            // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
            // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
            reverse(p1, &nums[n]);
        }
    };