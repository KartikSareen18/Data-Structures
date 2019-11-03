#include<iostream>
using namespace std;
struct trie
{
    bool endofword;
    struct trie *child[26];
};
struct trie* getNode()
{
    struct trie *node=new struct trie();
    node->endofword=false;
    for(int i=0;i<26;i++)
        node->child[i]=NULL;
    return node;

};
void insert1(struct trie *root,string str)
{
    struct trie *temp=root;
    for(int i=0;i<str.length();i++)
    {
        int index=str[i]-'a';
        if(temp->child[index]==NULL)
            temp->child[index]=getNode();
        temp=temp->child[index];
    }
    temp->endofword=true;
}
bool search1(struct trie *root,string str)
{
    struct trie *temp=root;
    for(int i=0;i<str.length();i++)
    {
        int index=str[i]-'a';
        if(temp->child[index]==NULL)
            return false;
        temp=temp->child[index];
    }
    return(temp!=NULL&&temp->endofword);
}
int main()
{
    int n;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++)
        cin>>str[i];
    struct trie *root=getNode();
    for(int i=0;i<n;i++)
        insert1(root,str[i]);
        string s;
        cin>>s;
        if(search1(root,s))
            cout<<"Yes";
        else
            cout<<"NO";

}
