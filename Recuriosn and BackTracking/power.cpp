#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1/x * myPow(1/x, -(n+1));
        if(n==0)
        return 1;


        double powerOfXByTwo=myPow(x,n/2);
        
        double powerOfX=powerOfXByTwo*powerOfXByTwo;
        if(n%2==1)
        powerOfX=powerOfX*x;

        return powerOfX;
    }
};