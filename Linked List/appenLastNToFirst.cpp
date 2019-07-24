//Append the last n elements of a linked list to the front
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

node* append_LinkedList(node* head,int n)
{
	node *temp=head;
  	int c=0;
  	while(temp!=NULL)
    {
      temp=temp->next;
      c++;
    }
  	int i=0;temp=head;
  	while(i<c-n-1)
    {
      temp=temp->next;
      i++;
    }
  	node *a=temp->next;
  	node *b=temp;
  	i=0;
  while(i<n)
  {
    b=b->next;
    i++;
  }
  b->next=head;
  temp->next=NULL;
  head=a;
  return head;
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
int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}
