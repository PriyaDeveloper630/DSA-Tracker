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
Node* middleofLL(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node* reverseLL(Node*&head){
    Node*curr=head;
    Node*prev=NULL;
    while(curr!=NULL){
        Node*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        
    }
    head=prev;
    return head;

}
bool isPalindrome(Node*&head){
    if (head==NULL||head->next==NULL)
    {
        return true;
    }
    //1->get middle of LL
    Node*mid=middleofLL(head);
    
    //2-> reverse LL after mid
    Node*temp=mid->next;
    mid->next=reverseLL(temp);
    //3 compare both halves
    Node*head1=head;
    Node*head2=mid->next;
    while (head2!=NULL)
    {
        if (head2->data!=head1->data)
        {
            return false;
        }
        else{
            head1=head1->next;
            head2=head2->next;
        }
    }
    
    return true;
    
}
int main()
{
    Node*node1= new Node(1); //dynamic node

    //head pointed to node1
    Node*head1=node1;
    Node*tail1=node1;
    addLasttoLL(head1,tail1,2);
    addLasttoLL(head1,tail1,3);
    addLasttoLL(head1,tail1,3);
    addLasttoLL(head1,tail1,2);
    addLasttoLL(head1,tail1,1);
    cout<<"original LL"<<endl;
    printLL(head1);
    bool ans=isPalindrome(head1);
    if(ans==true){
        cout<<"Yes palindrome";
    }
    else{
        cout<<"Not a palindrome";
    }
    

    
    return 0;
}