
// Definition for singly-linked list.
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;

        while(curr!=NULL)
        {  next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;

        }
        return prev;
    }

    ListNode* middle(ListNode* head)
    {
        if(head==NULL)
        return head;
        ListNode* dummy=new ListNode();
        ListNode* slow=dummy;
        dummy->next=head;
        ListNode* fast=dummy;
        
        while(fast &&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;

        }
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
   
      ListNode* middleNode= middle(head);
        ListNode* nextPart=reverse(middleNode->next);
        ListNode* temp=head;
        middleNode->next=nextPart;

        while(nextPart!=NULL)
        { if(nextPart==NULL&&temp!=NULL)
            return true;
          if(temp->val!=nextPart->val)
          return false;
          nextPart=nextPart->next;
          temp=temp->next;


        }
        
       
    

 return true;   }
};