#include<bits/stdc++.h>
using namespace std;

long long int dp[100][4][4], vi[100][4][4];

long long int f(long long int n, int prev, int prevprev)
{
	if(n==0) return 1;
	if(vi[n][prev][prevprev]) return dp[n][prev][prevprev];
	long long int ans=0;

	if(prev==2)
	{
		if(prevprev==1) ans+=f(n-1,3,prev);
		if(prevprev==3) ans+=f(n-1,1,prev);
	}

	if(prev!=1 && prev!=2) ans += f(n-1,1,prev);
	if(prev!=2 && n!=1 && prev!=0) ans += f(n-1,2,prev);
	if(prev!=3 && prev!=2) ans += f(n-1,3,prev);

	dp[n][prev][prevprev] = ans;
	vi[n][prev][prevprev] = 1;
	return dp[n][prev][prevprev];
}

int main()
{
	long long int n,ans;
	scanf("%lld",&n);
	ans = f(n,0,0);
	printf("%lld\n",ans);
	return 0;

}