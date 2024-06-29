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

int midsquarehash(long long n,int ts)
{
	int d=digitscount(ts-1);
	int l=digitscount(n);
	int e=(2*l-d)/2;
	int r=pow(10,e);
	n=(n*n)/r;
	int mod=pow(10,d);
	return (n)%mod;
}

int main()
{
	cout<<midsquarehash(1234,100)<<"\n";
	cout<<midsquarehash(4565,100);
	return 0;
}
