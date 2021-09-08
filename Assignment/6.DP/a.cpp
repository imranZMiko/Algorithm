#include<bits/stdc++.h>
using namespace std;

long long int dp[110],vi[110];

long long int f(long long int n)
{
	if(n==0) return 1;
	if(n<0) return 0;

	if(vi[n]) return dp[n];

	long long int ans=0;

	ans=f(n-1)+f(n-2)+4*f(n-3);

	dp[n]=ans;
	vi[n]=1;
	return dp[n];
}

int main()
{
	long long int ans,n;
	scanf("%lld",&n);
	ans = f(n);
	printf("%lld\n",ans);
	
	return 0;

}