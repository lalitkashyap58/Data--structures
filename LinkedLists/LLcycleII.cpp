#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        int check=0;
        ListNode *fast=head;
        if(head==NULL||head->next==NULL)//no node or single node
        {
            return NULL;
        }
        if(head->next==head)//self referential node
        {
            return head;
        }
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                check++;
                break;
            }
        }
        ListNode *curr1=head;
        ListNode *curr2=slow;
    if(check==1)
    {while(curr1!=curr2)
    {
        curr1=curr1->next;
        curr2=curr2->next;
        
    }
     return curr1;
    }
        else
            return NULL;
    }
};