#include<iostream>
using namespace std;

void insertionsort(int arr[])
{
	int key;
	int j=0;
	for(int i=1;i<5;i++)
	{
		key = arr[i];
		j = i - 1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

int main()
{
	int a[5];
	cout<<"enter 5 int numbers"<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
	}
	
	cout<<"before sorting"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	
	insertionsort(a);
	
	cout<<"after sorting"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}
