//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteNode(struct Node *head,int );

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T, i, n, l;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

	int kk;
	cin>>kk;
    head = deleteNode(head,kk);
    printList(head);
    }
    return 0;
}

// } Driver Code Ends


/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{   if(head==NULL)
return head;
if(head->next==NULL)
{
    delete head;
    return NULL;
}
if(x==1)
{
    head=head->next;
    return head;
}
int count=1;
    Node *get_prev=head;
    
    while(count!=x-1&&get_prev->next!=NULL)//getting the previous node of the node that has to be deleted
    {
       get_prev=get_prev->next;
       count++;
       
    }
    //check for the last Node
    
    Node *next_node=NULL;
    if(get_prev->next->next!=NULL)
    {next_node=get_prev->next->next;//getting the next node of the node that has to be deleted
    
    }delete get_prev->next;//deleting the node
    
    get_prev->next=next_node;//setting the connection again
    
    return head;
    
    //Your code here
}
