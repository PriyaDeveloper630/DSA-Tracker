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
void printLL(Node*&head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    
    Node*node1= new Node(10); //dynamic node

    //head pointed to node1
    Node*head=node1;
    cout<<"LL before insertion"<<endl;
    printLL(head);
    cout<<endl;
    int data;
    cout<<"Enter data to be inserted at head";
    cin>>data;
    addFirsttoLL(head,data);
    cout<<"LL after insertion"<<endl;
    printLL(head);

    
    return 0;
}