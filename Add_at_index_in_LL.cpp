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
void insertinLL(Node*&head,int data,int index){
    int n=sizeofLL(head);
    if(index<0 || index>n-1){
        cout<<"Invalid argument"<<endl;
    }
    else if(index==0){
        addFirsttoLL(head,data);
    }
    else if(index==n-1){
        addLasttoLL(head,data);
    }
    else{
        Node*add=new Node(data);
        Node*temp=head;
        int atPos=0;
        while(atPos<index-1){
            temp=temp->next;
            atPos++;
        }
        add->next=temp->next;
        temp->next=add;

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
    int data1;
    cout<<"Enter data to be inserted at front";
    cin>>data1;
    addFirsttoLL(head,data1);
    int data2;
    cout<<"Enter data to be inserted at end";
    cin>>data2;
    addLasttoLL(head,data2);
    cout<<"LL after insertion"<<endl;
    printLL(head);
    int n=sizeofLL(head);
    cout<<"size is "<<n<<endl;
    int idx;
    cout<<"Enter index where u want to insert";
    cin>>idx;
    int data3;
    cout<<"Enter data to be inserted at index";
    cin>>data3;
    insertinLL(head,data3,idx);
    cout<<"FinalLL "<<endl;
    printLL(head);

    
    return 0;
}