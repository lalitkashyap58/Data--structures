//{ Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  Node* dummy=new Node(-1);
  Node* head=dummy;
  Node* tail= dummy;
  while(head1&& head2)
  {
  if(head1->data<=head2->data)
  {
      tail->next=head1;//connection of tail 
            tail=head1;//tail shift on the node

            head1=head1->next;//putting head on another node
  }
  else
  {
      tail->next=head2;
      tail=head2;
      head2=head2->next;
     
  }
  }
  if(head2==NULL&&head1!=NULL)
   {
       while(head1)
       {
           tail->next=head1;
           tail=head1;
           head1=head1->next;
           
       }
   }
   else if(head1==NULL&&head2!=NULL)
   {while(head2)
       {
           tail->next=head2;
           tail=head2;
           head2=head2->next;
           
       }
       
   }
   else
   return head->next;
   
   return head->next;
   
   } // code here
 