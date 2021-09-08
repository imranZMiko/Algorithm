#include<bits/stdc++.h>
using namespace std;

long long int dp[110][110],arr[1000],vi[110][110],m;

long long int f(long long int n, int prev)
{
	if(n==0) return 1;

	if(vi[n][prev]) return dp[n][prev];
	
	long long int ans=0;

	for(int i=0;i<=9;i++)
	{
		if(prev!=100)
			if((i-prev)<=2 && (prev-i)<=2) 
				ans+=f(n-1,i);
		if(prev==100 && i!=0) ans+=f(n-1,i);
	}

	dp[n][prev]=ans;
	vi[n][prev]=1;
	return dp[n][prev];
}

int main()
{
	long long int ans,n;
	scanf("%lld",&n);
	ans = f(n,100);
	printf("%lld\n",ans);
	return 0;

}