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
void Kthposition(Node*&head,int k){
    if(k<=0){
        cout<<"Invalid argument";
    }
    Node*slow=head;
    Node*fast=head;
    for (int i = 0; i < k; i++)
    {
        fast=fast->next;
    }
    while (fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    cout<<"Element at "<<k<<" index from end is"<<slow->data<<endl;

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
    printLL(head);
    int k;
    cout<<"Enter kth index from last to be searched";
    cin>>k;

    Kthposition(head,k);
    

    
    return 0;
}