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
void middleofLL(Node*&head){
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<"The middle of above LL is"<<slow->data<<endl;
}
int main()
{
    
    Node*node1= new Node(10); //dynamic node

    //head pointed to node1
    Node*head1=node1;
    addLasttoLL(head1,20);
    addLasttoLL(head1,30);
    addLasttoLL(head1,40);
    addLasttoLL(head1,50);
    printLL(head1);
    middleofLL(head1);

    Node*node2= new Node(10);

    Node*head2=node2;
    addLasttoLL(head2,20);
    addLasttoLL(head2,30);
    addLasttoLL(head2,40);
    printLL(head2);
    middleofLL(head2);
    

    
    return 0;
}