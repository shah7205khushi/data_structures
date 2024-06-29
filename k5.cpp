//merge sort

#include<iostream>
using namespace std;

void merge(int a[],int l,int m,int r,int size)
{
	int i = l;
	int j = m+1;
	int k = l;
	
	int temp[size];
	
	while(i<=m && j<=r)
	{
		if(a[i] <= a[j])
		{
		
			temp[k] = a[i];
			i++;
			k++;
		
		}
		
		else
		{
			temp[k] = a[j];
			j++;
			k++;
			
		}
	}
	
	while(i <= m)
	{
		temp[k] = a[i];
		i++;
		k++;
	}
	
	while(j <= r)
	{
		temp[k] = a[j];
		j++;
		k++;
	}
	
	for(int p=l;p<=r;p++)
	{
		a[p]= temp[p];
	}
	
}

void mergesort(int a[],int l,int r,int size)
{
	if(l<r)
	{
		int m = (l+r)/2;
		mergesort(a,l,m,size);
		mergesort(a,m+1,r,size);
		
		merge(a,l,m,r,size);
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
	
	
	mergesort(ar,0,(size-1),size);
	
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		
	cout<<ar[i]<<" ";
	
	}
	cout<<endl;
	
	return 0;
}
