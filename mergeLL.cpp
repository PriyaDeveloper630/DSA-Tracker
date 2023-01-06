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
void addFirsttoLL(Node*&head,Node*&tail,int val){
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
Node* middleofLL(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* mergedLL(Node*head1,Node*head2){
    
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
Node* mergeSort(Node*head,Node*tail){
    if ((head == NULL) || (head->next == NULL)) {
        return head;
    }
    Node*mid=middleofLL(head);
    Node* left = head;
    Node* right = mid->next;
    mid -> next = NULL;
    left=mergeSort(left,mid);
    right=mergeSort(right,tail);
    Node*output=mergedLL(left,right);    
    return output;
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
    cout<<"Linked List before sorting ";
    printLL(head1);

    Node*output=mergeSort(head1,tail1);
    cout<<"Linked List after sorting ";
    printLL(output);

   

    
    

    
    return 0;
}