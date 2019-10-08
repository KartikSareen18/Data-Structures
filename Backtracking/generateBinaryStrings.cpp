#include<iostream>
using namespace std;

void binaryStrings(int arr[],int n,int i)
{
	if(i==n)
	{
		for(int j=0;j<n;j++)
			cout<<arr[j]<<" ";
		cout<<endl;
		return;
	}
	arr[i]=0;
	binaryStrings(arr,n,i+1);
	arr[i]=1;
	binaryStrings(arr,n,i+1);
}

int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	binaryStrings(arr,n,0);
}
