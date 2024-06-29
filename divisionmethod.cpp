#include<iostream>
#include<math.h>
using namespace std;

int nearest_prime(int ts)
{
	int i=0,j=0;
	int flag=0;
	for(i=ts;i>=2;i--)
	{
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
				break;
		}
		
		if(j>sqrt(i))
			return i;
	}
	
	if(flag==1)
		return 0;
		
	else
		return 1;	
}

int divisionhash(int key,int ts)
{
	int np=0;
	int l=0;
	np=nearest_prime(ts);
	l=key%np;
	return l;
}

int main()
{
	cout<<divisionhash(1234,100)<<"\n";
	cout<<divisionhash(2335,100);
	return 0;
}
