#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
long long int dp[1000][4];
long long int cost[1000][1000],vi[100][4];

long long int f(long long int n, int prev)
{
	if(n==0) return 0;
	if(vi[n][prev]) return dp[n][prev];
	long long int ans=0,a=inf,b=inf,c=inf,d;

	
	if(prev!=1) a = cost[n][0] + f(n-1,1);
	if(prev!=2) b = cost[n][1] + f(n-1,2);
	if(prev!=3) c = cost[n][2] + f(n-1,3);

	d=min(a,b);
	ans = min(d,c);
	dp[n][prev] = ans;
	vi[n][prev] = 1;
	return dp[n][prev];
}

int main()
{
	long long int ans,t,n,i,j;

	scanf("%lld",&t);

	for(i=1;i<=t;i++)
	{
		memset(cost,0,sizeof(cost));
		memset(vi,0,sizeof(vi));
		memset(dp,0,sizeof(dp));

		scanf("%lld",&n);
		for(j=1;j<=n;j++)
			scanf("%lld%lld%lld",&cost[j][0],&cost[j][1],&cost[j][2]);

		ans = f(n,0);
		printf("Case %lld: %lld\n",i,ans);

	}
	
	return 0;

}