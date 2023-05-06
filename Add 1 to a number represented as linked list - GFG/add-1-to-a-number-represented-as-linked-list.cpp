//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
   Node*reverseList(Node*head)
    {
        Node*prev = NULL;
        Node*curr = head;
        
        while(curr)
        {
            Node*next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        
        return prev;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        
        head = reverseList(head);
        Node*ans = head;
        
        int carry = 1;
        Node*prev = NULL;
        while(head && carry)
        {
            int sum = head->data + carry;
            carry = sum / 10;
            sum = sum % 10;
            head->data = sum;
            prev = head;
            head = head->next;
        }
        
        if(head)
        {
            return reverseList(ans);
        }
        if(carry)
        {
            Node*temp = new Node(carry);
            prev->next =temp;
            prev =temp;
        }
        return reverseList(ans);
        
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends