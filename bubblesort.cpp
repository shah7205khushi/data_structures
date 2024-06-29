#include<iostream>
using namespace std;

bubblesort(int a[])
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<(10-i-1);j++)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int main()
{
	int i;
	
	int a[10];
	
	
	cout<<"enter 10 int no "<<endl;
	for(i=0;i<10;i++)
	{
		cin>>a[i];
	}
	
	bubblesort(a);
	
	cout<<"sorted array : "<<endl;
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<"\t";
		
	}
	
	cout<<endl;
	return 0;
}
