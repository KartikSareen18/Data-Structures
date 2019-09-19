#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	vector<node<int>*> v;
  	queue<BinaryTreeNode<int>*> pending;
  	pending.push(root);
  	pending.push(NULL);
  	node<int> *head=NULL;
  	node<int> *tail=NULL;
  	while(pending.size()!=0)
    {
      BinaryTreeNode<int>*front=pending.front();
      pending.pop();
      if(front!=NULL)
      {
        node<int> *newNode=new node<int>(front->data);
        if(front->left!=NULL)
        pending.push(front->left);
		if(front->right!=NULL)
        pending.push(front->right);        
        if(head==NULL)
        {
          head=newNode;
          tail=newNode;
        }
        else
        {
          tail->next=newNode;
          tail=tail->next;
        }
      }
      else
      {
        v.push_back(head);
        head=NULL;
        tail=NULL;
        if(pending.size()!=0)
        pending.push(NULL);
      }
    }
  	return v;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
	    print(ans[i]);
    }
}
