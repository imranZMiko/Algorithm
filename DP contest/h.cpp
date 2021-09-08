#include<bits/stdc++.h>
using namespace std;

long long int dp[110][110],m;
long long int arr[1000],vi[110][110];

long long int f(long long int n, int prev)
{
	
	if(n==0) return 1;
	if(vi[n][prev]) return dp[n][prev];

	long long int ans=0;

	for(int i=0;i<m;i++)
	{
		if(prev!=100)
			if((arr[i]-prev)<=2 && (prev-arr[i])<=2) 
				ans += f(n-1,arr[i]);
		if(prev==100) ans += f(n-1,arr[i]);
	}

	dp[n][prev] = ans;
	vi[n][prev] = 1;
	return dp[n][prev];
}

int main()
{
	long long int ans,t,i,j,n;

	scanf("%lld",&t);

	for(i=1;i<=t;i++)
	{
		ans=0;
		memset(arr,0,sizeof(arr));
		memset(vi,0,sizeof(vi));
		memset(dp,0,sizeof(dp));

		scanf("%lld%lld",&m,&n);
		for(j=0;j<m;j++)
			scanf("%lld",&arr[j]);

		ans = f(n,100);
		printf("Case %lld: %lld\n",i,ans);

	}
	
	return 0;

}