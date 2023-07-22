//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
         Node* zero=new Node(-1);
        Node* ones=new Node(-1);
        Node* twos=new Node(-1);
        Node *temp1=zero;
        Node *temp2=ones;
        Node *temp3=twos;
        Node*temp=head;
        Node* nex=NULL;
        while(temp){
            if(temp->data==0)
            {
                temp1->next=temp;
                nex=temp->next;
                temp1=temp1->next;
                temp->next=NULL;
                temp=nex;
            }
            else if(temp->data==1)
            {
                temp2->next=temp;
                nex=temp->next;
                temp2=temp2->next;
                temp->next=NULL;
                temp=nex;
            }
            else if(temp->data==2){
                temp3->next=temp;
                nex=temp->next;
                temp3=temp3->next;
                temp->next=NULL;
                temp=nex;
            }
        }
     
        temp2->next=twos->next;
        temp1->next=ones->next;
        return zero->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends