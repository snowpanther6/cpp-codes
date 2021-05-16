#include<bits/stdc++.h>
using namespace std;
 
 struct Node{
     int data;
     Node* next;
     Node(int val){
         data = val;
         next = NULL;
     }
 };
 
 void insertNode(Node* &head,int val){
     Node* temp = new Node(val);
     if(head == NULL){
         head = temp;
     }
     else {
         head->next = temp;
         head = head->next;
     }
 }
 
 
 Node* reverseNode(Node* head){
     Node* prev = NULL;
     Node* cur = head;
     while(cur){
         Node* new1 = cur->next;
         cur->next = prev;
         prev = cur;
         cur = new1;
     }
     return prev; 
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
