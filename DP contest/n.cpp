#include<bits/stdc++.h>
using namespace std;

long long int dp[1005][1005], vi[1005][1005];
char a[1005];

long long int f(long long int ia,long long int ib)
{
	if(ia<ib) return 0;
	if(ia==ib) return 0;

	if(vi[ia][ib]) return dp[ia][ib];
	long long int ans=0,x=0,y=0,z=0;

	if(a[ia]==a[ib]) ans=f(ia-1,ib+1);
	else
	{
		x=f(ia-1,ib+1)+1;
		y=f(ia-1,ib)+1;
		z=f(ia,ib+1)+1;
		ans=min(x,(min(y,z)));
	}

	dp[ia][ib]=ans;
	vi[ia][ib]=1;
	return dp[ia][ib];
}

int main()
{
	long long int ans;
	int t,i;
	scanf("%d",&t);

	for(i=1;i<=t;i++)
	{
		memset(vi,0,sizeof(vi));
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		
		scanf("%s",a);
		ans=0;
		ans=f(strlen(a)-1,0);
		printf("Case %d: %lld\n",i,ans);
		

	}
	
	return 0;

}
