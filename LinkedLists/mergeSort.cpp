#include<iostream>
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
    private:
      ListNode* merge2lists(ListNode* list1, ListNode* list2) {
        ListNode* dHead=new ListNode(-1);
        ListNode* tail=dHead;
        while(list1!=NULL&&list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                tail->next=list1;
                tail=list1;
                list1=list1->next;
            }
            else
            {
                tail->next=list2;
                tail=list2;
                list2=list2->next;
            }
        }
        if(list1==NULL&&list2!=NULL)
        {
            tail->next=list2;
            tail=list2;
            list2=list2->next;
        }
         if(list2==NULL&&list1!=NULL)
        {
            tail->next=list1;
            tail=list1;
            list1=list1->next;
        }
        return dHead->next;
    }
    
    
    ListNode* middle(ListNode* head)
    {   ListNode* dummy=new ListNode();
        ListNode* slow=dummy;
        ListNode* fast= dummy;
        dummy->next=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
        }
        return slow;
    }
     ListNode* helper(ListNode* head)
     {
         if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* mid= middle(head);
        ListNode* midNext=mid->next;//head of half part of linked list
        mid->next=NULL;//diving into two parts
        ListNode* left=helper(head);
        ListNode* right=helper(midNext);
        return merge2lists(left,right);

     }
public:
    ListNode* sortList(ListNode* head) {
        return helper(head);


    }
};