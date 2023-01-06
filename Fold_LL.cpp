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
void FoldLL(Node*&head){
    Node*p=head;
    int l,i;
    vector<Node*>v;
    while(p!=NULL)
    {
        v.push_back(p);
        p=p->next;
    }
    l=v.size();
    p=head;
     
    for(i=0;i<l/2;i++)
    {
        if(i!=0)
        {
            p->next=v[i];
            p=p->next;
        }
        p->next=v[l-i-1];
        p=p->next;
    }
     
    if(l%2==1)
    {
        p->next=v[i];
        p=p->next;
    }
    p->next=NULL;
    
}
int main()
{
    Node*node1= new Node(1); //dynamic node

    //head pointed to node1
    Node*head1=node1;
    Node*tail1=node1;
    addLasttoLL(head1,tail1,2);
    addLasttoLL(head1,tail1,3);
    addLasttoLL(head1,tail1,4);
    addLasttoLL(head1,tail1,5);
    addLasttoLL(head1,tail1,6);
    addLasttoLL(head1,tail1,7);
    cout<<"original LL"<<endl;
    printLL(head1);
    FoldLL(head1);
    cout<<"LL after fold"<<endl;
    printLL(head1);
    

    
    return 0;
}