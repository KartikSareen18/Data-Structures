#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Interval
{
	public:
	char id;
	int start;
	int end;	
};

bool cmp(Interval a,Interval b)
{
	return a.end<b.end;
}
void intervalSequencing(Interval arr[],int n)
{
	sort(arr,arr+n,cmp);
	int last_finish=arr[0].end;
	queue<Interval>q;
	q.push(arr[0]);
	for(int i=1;i<n;i++)
	{
		if(arr[i].start>=last_finish)
		{
			q.push(arr[i]);
			last_finish=arr[i].start;
		}
	}
	while(!q.empty())
	{
		Interval a=q.front();
		q.pop();
		cout<<a.id<<" ";
	}
}

int main()
{
	int n;
	cout<<"Enter n: ";
	cin>>n;
	Interval arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter id, start time and end time: ";
		cin>>arr[i].id>>arr[i].start>>arr[i].end;
	}
	intervalSequencing(arr,n);
}
