//bubble sort

#include<iostream>
using namespace std;

void bubblesort(int a[],int size)
{
	
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
}

int main()
{
	int size;
	
	
	cout<<"enter the size of the array"<<endl;
	cin>>size;
	
	int ar[size];
	
	cout<<"enter the "<<size<<" int numbers"<<endl;
	for(int i=0;i<size;i++)
	{

	cin>>ar[i];
	
	}
	cout<<"before sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		
	cout<<ar[i]<<" ";
	
	}
	cout<<endl;
	
	
	bubblesort(ar,size);
	
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		
	cout<<ar[i]<<" ";
	
	}
	cout<<endl;
	
	return 0;
}
