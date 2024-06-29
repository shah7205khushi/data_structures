//heapsort

#include<iostream>
using namespace std;

void heapify(int a[],int n,int i)
{
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(left < n && a[left] > a[largest])
	largest = left ;
	
	if(right < n && a[right] > a[largest])
	largest = right;
	
	if(largest != i)
	{
		int temp  = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		
		heapify(a,n,largest);
	}
}

void heapsort(int a[],int n)
{
	for(int i = n/2 - 1; i>=0 ; i--)
	{
		heapify(a,n,i);
	}
	
	for(int i = n - 1; i>=0 ; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		
		heapify(a,i,0);
	}
}
int main()
{
	int size,n;
	
	
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
	
	
	heapsort(ar,size);
	
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		
	cout<<ar[i]<<" ";
	
	}
	cout<<endl;
	
	return 0;
}
