//selection sort

#include<iostream>
using namespace std;

void selectionsort(int a[],int size)
{
	
	for(int i=0;i<size;i++)
	{
		for(int j=i;j<size;j++)
		{
			if(a[i]>a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
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
	
	
	selectionsort(ar,size);
	
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		
	cout<<ar[i]<<" ";
	
	}
	cout<<endl;
	
	return 0;
}
