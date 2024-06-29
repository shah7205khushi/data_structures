#include<iostream>
using namespace std;

selectionsort(int *a,int n)
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

int main()
{
	int i;
	
	int a[10];
	int y;
	
	cout<<"enter 10 int no "<<endl;
	for(i=0;i<10;i++)
	{
		cin>>a[i];
	}
	
	selectionsort(a,y);
	
	cout<<"sorted array : "<<endl;
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<"\t";
		
	}
	
	cout<<endl;
return 0;	
}
