#include<iostream>
using namespace std;
/// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* Middle(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
        }
        
        ListNode* head2=slow->next;
        slow->next=NULL;
        return head2;
        
        
        
    }
    ListNode* reverse(ListNode* head)
    {   
        ListNode*  prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            
        }
        return prev;
        
    }
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        
        ListNode* curr1=head1;
        ListNode* curr2=head2;
        
        while(curr1!=NULL&&curr2!=NULL)
        {
            ListNode* next1=curr1->next;
            ListNode* next2=curr2->next;
            
            curr1->next=curr2;
            curr2->next=next1;
            
            curr1=next1;
            curr2=next2;
            
            
        }
        return head1;
    }
    void reorderList(ListNode* head) {
        if(head==NULL)
            return;
     
        ListNode* middle=Middle(head);//finding the middle of the linked list 
        middle=reverse(middle);
        merge(head,middle);
      
        
    }
};