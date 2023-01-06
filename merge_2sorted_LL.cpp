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
Node* mergedLL(Node*&head1,Node*&head2){
    
    Node*temp1=head1;
    Node*temp2=head2;
    Node*head3=temp1;
    if(temp2==NULL){
        return temp1;
    }
    else if(temp1==NULL){
        return temp2;
    }
    
    else{

        if (temp1->data>=temp2->data){
            head3=temp2;
            temp2=temp2->next;
        }
        else{
            temp1=temp1->next;
        }
        Node*temp3=head3;
        while (temp1!=NULL && temp2!=NULL)
        {   if(temp1->data<=temp2->data){
                temp3->next=temp1;
                temp1=temp1->next;
            }
            else{
                temp3->next=temp2;
                temp2=temp2->next;
                
            }
            temp3=temp3->next;
                
        }
        while (temp1!=NULL )
        {   
            temp3->next=temp1;
            temp3=temp3->next;
            temp1=temp1->next;
            
        }
        while (temp2!=NULL )
        {   
            temp3->next=temp2;
            temp3=temp3->next;
            temp2=temp2->next;
            
        }
    } 
        
    
    return head3;
    
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
    

    Node*node2= new Node(5);

    Node*head2=node2;
    addLasttoLL(head2,10);
    addLasttoLL(head2,15);
    addLasttoLL(head2,80);
    printLL(head2);

    //print merged sorted LL
    Node*output=mergedLL(head1,head2);
    printLL(output);
    
    

    
    return 0;
}