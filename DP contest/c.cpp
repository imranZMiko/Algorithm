#include <bits/stdc++.h>
using namespace std;
long long int vi[505][505], dp[505][505],n;

long long int f(long long int m, long long int amount)
{
	if(amount==0) return 1;
	if(amount<0) return 0;
	if(m==0) return 0; 	
	if(vi[m][amount]) return dp[m][amount];
	long long int ans=0,a,b;

	a=f(m-1,amount);
	b=f(m-1,amount-m);

	ans=a+b;
	dp[m][amount] = ans;
	vi[m][amount] = 1;
	return dp[m][amount];
}

int main()
{
	long long int ans;
	memset(vi,0,sizeof(vi));

	scanf("%lld",&n);

	ans=f(n-1,n);
	printf("%lld\n",ans);
	return 0;
}