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
void Add2LL(Node* head1, Node* head2)
{
    Node*temp1=head1;
    Node*temp2=head2;
    vector<int> v1;
    vector<int> v2;
    
    while (temp1!=NULL)
    {
        v1.push_back(temp1->data);
        temp1=temp1->next;
        
    }
    reverse(v1.begin(),v1.end());
    while (temp2!=NULL)
    {
        v2.push_back(temp2->data);
        temp2=temp2->next;
        
    }
    reverse(v2.begin(),v2.end());
    vector<int>v3;
    int carry,sum=0;
    int i,j=0;
    while(i<v1.size()&&j<v2.size()){
        sum=(v1.at(i)+v2.at(j)+carry);
        int s=sum/10;
        carry=(sum)/10;
        v3.push_back(s);
        i++;
        j++;

    }
    while(i<v1.size()){
        int add=v1[i];
        v3.push_back(add);
        i++;
    }
    while(j<v2.size()){
        int add=v2[j];
        v3.push_back(add);
        j++;
    }
    for (auto it :v3)
    {
        cout<<it<<" ";
    }
    
}
int main()
{
    Node*node1= new Node(7); //dynamic node

    //head pointed to node1
    Node*head1=node1;
    Node*tail1=node1;
    addLasttoLL(head1,tail1,5);
    addLasttoLL(head1,tail1,9);
    addLasttoLL(head1,tail1,4);
    addLasttoLL(head1,tail1,6);
    
    

    Node*node2= new Node(8);
    Node*head2=node2;
    Node*tail2=node2;
    addLasttoLL(head2,tail2,4);
    
    
    Add2LL(head1,head2);

    
    return 0;
}