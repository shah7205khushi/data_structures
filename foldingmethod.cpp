//folding method (hashing)

#include<iostream>
#include<math.h>
using namespace std;

int digitscount(int n)
{
	int c=0;
	while(n!=0)
	{
		c++;
		n=n/10;
	}
	
	return c;
}

foldinghash(long long n,int ts)
{
	int d=digitscount(ts-1);
	int mod=pow(10,d);
	int sum=0;
	while(n!=0)
	{
		sum=sum+n%mod;
		n=n/mod;
	}
	return sum%ts;
}

int main()
{
	cout<<foldinghash(1234,100)<<"\n";
	cout<<foldinghash(4565,100);
}
