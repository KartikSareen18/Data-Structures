#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node *reverse_linked_list_rec(node *head)
{
    if(head->next==NULL || head==NULL)
      return head;
  	node *small=reverse_linked_list_rec(head->next);
    node *temp=small;
  	while(temp->next!=NULL)
    {
      temp=temp->next;
    }
  	temp->next=head;
  	temp=temp->next;
  	temp->next=NULL;
  	return small;
}


node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* head=takeinput();
    head=reverse_linked_list_rec(head);
    print(head);
    return 0;
}



