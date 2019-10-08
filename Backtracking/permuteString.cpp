#include<iostream>
#include<string.h>
using namespace std;

void swap(char *a,char *b)
{
	char t=*a;
	*a=*b;
	*b=t;
}
void permutations(string s,int si,int ei)
{
	if(si==ei)
	{
		cout<<s<<endl;
		return;
	}	
	for(int i=si;i<=ei;i++)
	{
		swap(s[si],s[i]);
		permutations(s,si+1,ei);
		swap(s[si],s[i]);
	}
}

int main()
{
	string c;
	cin>>c;
	int n=c.size();
	permutations(c,0,n-1);
}
