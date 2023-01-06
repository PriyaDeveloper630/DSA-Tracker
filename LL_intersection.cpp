#include <bits/stdc++.h>
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
    cout<<endl;
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
Node* IntersectionNode(Node* head1, Node* head2)
{
    while (head2) {
        Node* temp = head1;
        while (temp) {
            // if both Nodes are same
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // intersection is not present between the lists
    return NULL;
}
int main()
{
    Node*node1= new Node(3); //dynamic node

    //head pointed to node1
    Node*head1=node1;
    Node*tail1=node1;
    addLasttoLL(head1,tail1,6);
    addLasttoLL(head1,tail1,9);
    addLasttoLL(head1,tail1,15);
    addLasttoLL(head1,tail1,30);
    
    cout<<"First LL"<<endl;
    printLL(head1);

    Node*node2= new Node(10);
    Node*head2=node2;
    Node*tail2=node2;
    addLasttoLL(head2,tail2,15);
    addLasttoLL(head2,tail2,30);
    cout<<"Second LL"<<endl;
    printLL(head2);

    
    Node*ans=IntersectionNode(head1,head2);
    if(!ans){
        cout<<"no intersection"<<endl;
    }
    else{
        cout<<"The LL intersect at"<<ans->data;
    }
    

    
    return 0;
}