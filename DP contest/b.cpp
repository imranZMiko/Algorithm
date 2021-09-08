#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
long long int vi[1010][1010], grid[1010][1010];
double dp[1010][1010];
int n,m;
double f(int x, int y)
{
	if(x==n+1 && y==m+1) return 0;
	if(x>n+1 || y>m+1) return inf;
	if(vi[x][y]) return dp[x][y];
	double ans=0,a,b,c=inf,d;

	a = 100 + f(x+1,y);
	b = 100 + f(x,y+1);
	if(grid[x][y]) c = 100*sqrt(2) + f(x+1,y+1);

	d=min(a,b);
	ans = min(d,c);
	dp[x][y] = ans;
	vi[x][y] = 1;
	return dp[x][y];
}

int main()
{
	int k,d,c;
	double ans;
	memset(grid, 0, sizeof(grid));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&d,&c);
		grid[d][c]=1;
	}
	ans = f(1,1);
	printf("%.0lf\n",ans);
	return 0;

}