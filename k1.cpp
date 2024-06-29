//insertion sort 

#include<iostream>
using namespace std;

int main()
{
	int i,j,temp;
	int a[5];
	
		cout<<"enter the 5 elements"<<endl;
	for(i=0;i<5;i++)
	{
	
		cin>>a[i];
	}
	
	cout<<"before sorting"<<endl;
	
	for(i=0;i<5;i++)
	{
		
	cout<<a[i]<<endl;
	}
	
	for(i=0;i<5;i++)
	{
		temp=a[i];
		j=i-1;
		
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
	
		a[j+1]=temp;
	}
	
	
	cout<<"after sorting"<<endl;
	
	for(i=0;i<5;i++)
	{
		
	cout<<a[i]<<endl;
	}
}
