#include<iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lhead=new ListNode(-1);
        ListNode* ltail=lhead;
        ListNode* rhead=new ListNode(-1);
        ListNode* rtail=rhead;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                ltail->next=head;
                ltail=head;
                
            }
            else
            {
                rtail->next=head;
                rtail=head;
            }
            head=head->next;
        }
        ltail->next=rhead->next;
        rtail->next=NULL;
    
        return  lhead->next;
        
        
    }
};