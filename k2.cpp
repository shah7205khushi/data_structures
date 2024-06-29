//binary search

#include<iostream>
using namespace std;

sort(int *a,int n)
{
	for(int i=0;i<10;i++)
	{
		for(int j=i;j<10;j++)
		{
			if(a[i]>a[j])
			{
				int temp = a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

int binarysearch(int arr[],int left ,int right,int x)
{
	while(left<=right)
	{
		int mid = left + (right-left)/2;
		if(arr[mid] == x)
		{
			return mid;
		}
		
		else if(arr[mid]<x)
		{
			left = mid+1;
		}
		
		else
		{
			right =  mid-1;
		}
		
	}
	
	return -1;
}


int main()
{
	int i;
	int num;
	int output;
	int a[10];
	int y;
	
	cout<<"enter 10 int no :"<<endl;
	for(i=0;i<10;i++)
	{
		cin>>a[i];
	}
	
	sort(a,y);
	
	cout<<"sorted array"<<endl;
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<"\t";
		
	}
	
	cout<<endl;
	
	cout<<"enter the number that you want to search"<<endl;
	cin>>num;
	
	output=binarysearch(a,0,9,num);
	
	if(output == -1)
	{
		cout<<"element not found"<<endl;
	}
	else
	{
		cout<<"element found at the postion :"<<output<<endl;
	}
	return 0;
}
