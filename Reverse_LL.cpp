#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node*next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};
void addFirsttoLL(Node*&head,int val){
    Node*temp=new Node(val);
    temp->next=head;
    head=temp;

}
void addLasttoLL(Node*&head,int val){
    Node*add=new Node(val);
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=add;

}
void printLL(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void reverseLL(Node*&head){
    Node*curr=head;
    Node*prev=NULL;
    while(curr!=NULL){
        Node*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }
    head=prev;

}
int main()
{
    
    Node*node1= new Node(10); //dynamic node

    //head pointed to node1
    Node*head=node1;
    addLasttoLL(head,20);
    addLasttoLL(head,30);
    addLasttoLL(head,40);
    addLasttoLL(head,50);
    cout<<"LL before deletion"<<endl;
    printLL(head);
    
    cout<<"LL after reversal"<<endl;
    reverseLL(head);
    printLL(head);

    
    return 0;
}