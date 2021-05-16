#include<bits/stdc++.h>
using namespace std;
 
 struct Node{
     int data;
     Node* next;
     Node* prev;
     Node(int val){
         data = val;
         next = NULL;
         prev = NULL;
     }
 };
 
 void insertNode(Node* &head,int val){
     Node* temp = new Node(val);
     if(head == NULL){
         head = temp;
     }
     else {
         head->next = temp;
         temp->prev = head;
         head = head->next;
     }
 }
 
 
 Node* reverseNode(Node* head){
     Node* cur = head;
     while(cur->next!=NULL)
        cur = cur->next;
    head = cur;
    while(cur){
        Node* temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = cur->next;
    }
    return head;
      
 }
 void printNode(Node* head){
     while(head){
         cout<<head->data<<" ";
         head = head->next;
     }
 }

int main() {
    
    int n;
    cin>>n;
    Node* cur = NULL;
    Node* head = cur;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        insertNode(cur,x);
        if(i==0){
            head = cur;
        }
    }
    head = reverseNode(head);
    printNode(head);

    return 0;
}
