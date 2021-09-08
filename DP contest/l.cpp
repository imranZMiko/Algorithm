#include<bits/stdc++.h>
using namespace std;

long long int dp[1005][1005], vi[1005][1005];
char a[1005],b[1005];

long long int f(long long int ia,long long int ib)
{
	if(ia==-1 || ib==-1) return 0;

	if(vi[ia][ib]) return dp[ia][ib];
	long long int ans=0,x=0,y=0,z=0;

	if(a[ia]==b[ib] && a[ia]!='\n')
	{
		x=f(ia-1,ib-1)+1;
		ans=x;
	}
	else
	{
		y=f(ia-1,ib);
		z=f(ia,ib-1);
		ans=max(y,z);
	}

	dp[ia][ib]=ans;
	vi[ia][ib]=1;
	return dp[ia][ib];
}

int main()
{
	long long int ans;

	while(fgets(a,1005,stdin)!=NULL && fgets(b,1005,stdin)!=NULL)
	{
		memset(vi,0,sizeof(vi));
		memset(dp,0,sizeof(dp));
		ans=0;
		ans=f(strlen(a)-1,strlen(b)-1);
		printf("%lld\n",ans);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));

	}
	
	return 0;

}
