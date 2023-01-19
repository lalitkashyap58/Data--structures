

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* solve(ListNode* l1,ListNode* l2)
    {int carry=0;
     ListNode* dummy=new ListNode();
     ListNode* tail=dummy;
     while(l1!=NULL||l2!=NULL||carry!=0)
     {
         
         int d1=(l1==NULL)?0:l1->val;
         int d2=(l2==NULL)?0:l2->val;
         ListNode* temp=new ListNode((d1+d2+carry)%10);
         carry=(d1+d2+carry)/10;
         tail->next=temp;
         tail=temp;
         if(l1!=NULL)
             l1=l1->next;
         if(l2!=NULL)
             l2=l2->next;
         
     }
     dummy=dummy->next;
     return dummy;
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return solve(l1,l2);
        
    }
};