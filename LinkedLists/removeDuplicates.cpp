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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dHead=new ListNode(-1);
        ListNode* original=dHead;
        while(head!=NULL)
        {
            if(head->next==NULL||head->val!=head->next->val)
            {
                original->next=head;
                original=head;
                head=head->next;
            }else
            {
                ListNode* curr=head;
                while(curr!=NULL&&curr->val==head->val)
                {
                    curr=curr->next;
                }
                
                head=curr;
                
            }
        }
        original->next=NULL;
        return dHead->next; 
    }
};