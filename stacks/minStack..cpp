#include<iostream>
#include<stdio.h>
using namespace std;
class MinStack {
public:
long long MinElement; //It will store minimum element
stack<long long> s;
MinStack() {

}

void push(int val) {
    
    if(s.size()==0){
    s.push(val);
    MinElement = val;
    }
    
    else{
    if(val>=MinElement)
    {
        s.push(val);
    }
    else if(val<MinElement)
    {
        s.push((long long)2*val-MinElement);
        MinElement = val;
    }
    }
}

void pop() {
    if(s.size()==0)
      return;
    
    if(s.top()>=MinElement)
    {
        s.pop();
    }
    else if(s.top()<MinElement)
    {
        MinElement = (long long)2*MinElement - s.top();
        s.pop();
    }
}

int top() {
    int x = -1;
    
    if(s.size()==0)
       return x;
    
    if(s.top()>=MinElement)
    {
        x = s.top();
    }
    else if(s.top()<=MinElement)
        x = MinElement;
    
    return x;
    
}

int getMin() {
    
    if(s.size()==0)
        return -1;
    else return MinElement;
    
}
};
