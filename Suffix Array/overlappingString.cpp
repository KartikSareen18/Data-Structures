#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct suffix
{
	int index;
	char *suff;
};
int cmp(struct suffix a,struct suffix b)
{
	return strcmp(a.suff,b.suff)<0?1:0;
}
int * buildSuffixArray(char *str)
{
	int n=strlen(str);
	struct suffix s[n];
	for(int i=0;i<n;i++)
	{
		s[i].index=i;
		s[i].suff=str+i;
	}
	sort(s,s+n,cmp);
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		arr[i]=s[i].index;
	return arr;
}
char * overlappingStr(int *arr,char *str)
{
	int n=strlen(str);
	int max=0;
	char *temp=NULL;
	for(int i=0;i<n-1;i++)
	{
		int res=strncmp(str+arr[i],str+arr[i+1],strlen(str+arr[i]));
		if(res==0)
		{
			if(max<strlen(str+arr[i]))
			{
				max=strlen(str+arr[i]);
				temp=str+arr[i];
			}
		}
	}
	return temp;
}

int main()
{
	char str[100];
	cin>>str;
	int n=strlen(str);
	int *arr=buildSuffixArray(str);
	char *res=overlappingStr(arr,str);
	cout<<((res==NULL)?"No overlapping substring":res)<<endl;
	
}
