#include<bits/stdc++.h>
using namespace std;
#define inf 1e5
unsigned long long  dp[1000][1000], vi[1000][1000], grid[1000][1000];
unsigned long long  n;

unsigned long long  f(unsigned long long  x, unsigned long long  y)
{
	
	if(x==(2*n-2) && y==0) return grid[x][y];
	if(x>(2*n-2) || y<0) return 0;
	if((x>n-1 && y>2*n-2-x) || (x<=n-1 && y>x)) return 0;

	if(vi[x][y]) return dp[x][y];
	unsigned long long  ans=0,a=0,b=0;

	if(x>=n-1 && y==0) a=f(x+1,y);
	else if(x>=n-1 && y>=(2*n-x-1)/2)
	{
		a=f(x+1,y);
		b=f(x+1,y-1);
	}
	else 
	{
		a=f(x+1,y);
		b=f(x+1,y+1);
	}

	ans=grid[x][y]+max(a,b);
	
	dp[x][y] = ans;
	vi[x][y] = 1;
	return dp[x][y];
}

int main()
{
	unsigned long long  ans,t,m=0,i,j,k;
	scanf("%llu",&t);
	for(i=1;i<=t;i++)
	{
		memset(grid,0,sizeof(grid));
		memset(vi,0,sizeof(vi));
		memset(dp,0,sizeof(dp));
		scanf("%llu",&n);
		for(j=0;j<2*n-1;j++)
		{
			if(j<=n-1) m=j+1;
			else m--;
			for(k=0;k<m;k++)
			{
				scanf("%llu",&grid[j][k]);
				
			}
		}
		ans=f(0,0);
		printf("Case %llu: %llu\n",i,ans);
	}
	return 0;

}