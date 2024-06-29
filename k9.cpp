#include<iostream>
using namespace std;

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
	
	int j=0;
	int key;
	
	for(int i=0;i<size;i++)
	{
		key = ar[i];
		j=i-1;
		
		while(j >= 0 && ar[j] >= key)
		{
	
		ar[j+1] = ar[j];
		j--;
		
		}
		
		ar[j+1] = key;
	}
	
	
	
	cout<<"After sorting"<<endl;
	for(int i=0;i<size;i++)
	{
		
	cout<<ar[i]<<" ";
	
	}
	cout<<endl;
	
	return 0;
}
