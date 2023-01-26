#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    bool possible(vector<int> &piles,int h,int sp)
    {
        long long time=0;
        for(int i=0;i<piles.size();i++)
        {    if(sp!=0)
            time+=piles[i]/sp;
            if(sp!=0&&piles[i]%sp!=0)
            {
                time++;
            }
            
        }
        return time<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        
        
        int maxi=1;
        for(int i=0;i<piles.size();i++)
        {
            maxi=max(maxi,piles[i]);
        }
        if(h==piles.size())
        return maxi;

        long low=1;
        long long high=maxi;
        long long speed=0;
        
        while(low<=high)
        {
            long long sp=low+(high-low)/2;
            if(possible(piles,h,sp)==true)
            {
                speed=sp;
                high= sp-1;
            }
            else
            {
                low=sp+1;
            }

        }
        return speed;
    }
};