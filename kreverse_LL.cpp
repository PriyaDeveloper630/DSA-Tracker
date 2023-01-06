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
void addLasttoLL(Node*&head,Node*&tail,int val){
    Node*add=new Node(val);
    Node*temp=tail;
    temp->next=add;
    tail=tail->next;
}
void printLL(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int sizeofLL(Node*&head){
    int size=0;
    Node*temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    return size;
}
Node* kReverse(Node*&head,int k){
    if (head==NULL)
    {
        return NULL;
    }
    //1->reverse k nodes first;
    Node*next=NULL;
    Node*curr=head;
    Node*prev=NULL;
    int count=0;
    while (curr!=NULL && count<k)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    //2-> rest nodes to recursion
    if (next!=NULL)
    {
        head->next=kReverse(next,k);

    }
    //3 return head of reversed LL
    return prev;
    
}
int main()
{
    Node*node1= new Node(10); //dynamic node

    //head pointed to node1
    Node*head1=node1;
    Node*tail1=node1;
    addLasttoLL(head1,tail1,9);
    addLasttoLL(head1,tail1,8);
    addLasttoLL(head1,tail1,7);
    addLasttoLL(head1,tail1,12);
    addLasttoLL(head1,tail1,11);
    addLasttoLL(head1,tail1,4);
    addLasttoLL(head1,tail1,5);
    cout<<"LL before k reversal"<<endl;
    printLL(head1);
    Node*output=kReverse(head1,3);
    cout<<"LL after k reversal"<<endl;
    printLL(output);

    

    
    return 0;
}