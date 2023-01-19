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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenHead=new ListNode(-1);
        ListNode* evenTail=evenHead;
    ListNode* oddHead=new ListNode(-1);
    ListNode* oddTail=oddHead;
        int flag=1;
    while(head!=NULL)
    {
        if(flag==0)
        {   
            evenTail->next=head;
            evenTail=head;
            flag=1;
        }
         else if(flag==1)
        {  flag=0;
            oddTail->next=head;
                oddTail=head;
               
        }
        head=head->next;
     
    }
    oddTail->next=evenHead->next;
    evenTail->next=NULL;
        return oddHead->next;
    }
    
};