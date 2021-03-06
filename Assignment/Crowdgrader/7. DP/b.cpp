/*
Given two integer sequences A and B, find the longest common increasing subsequence between A and B.

Input
First line: NandM(0<N,M≤100), length of A and B correspondingly. Second line: N integers denoting A. Each of these integers will be between -1000 to 1000. Third line: M integers denoting B. Each of these integers will be between -1000 to 1000.

Output
Output the length of longest common increasing subsequence of A and B. See sample for clarification.

Sample
Input
-------
7 6
1 2 3 1 2 3 1
1 3 2 3 1 5

Output
--------
3
*/

#include<bits/stdc++.h>
using namespace std;

long long int dp[105][105][2005], vi[105][105][2005];
long long int a[1005],b[1005],n,m;

long long int f(long long int ia,long long int ib, long long int st)
{
	if(ia==n || ib==m) return 0;

	if(vi[ia][ib][st]) return dp[ia][ib][st];
	long long int ans=0,x=0,y=0,z=0,k=0;

	if(a[ia]==b[ib] && a[ia]>=st)
	{
		x=f(ia+1,ib+1,a[ia])+1;
		k=f(ia+1,ib+1,st);
		ans=max(x,k);
	}
		
	else
	{
		y=f(ia+1,ib,st);
		z=f(ia,ib+1,st);
		ans=max(y,z);
	}
	
	dp[ia][ib][st]=ans;
	vi[ia][ib][st]=1;
	return dp[ia][ib][st];
}

int main()
{
	long long int ans = 0;
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]=a[i]+1001;
	} 
	for(int j=0;j<m;j++)
	{
		scanf("%lld",&b[j]);
		b[j]=b[j]+1001;
	} 

	memset(vi,0,sizeof(vi));
	memset(dp,0,sizeof(dp));
	ans=f(0,0,0);
	printf("%lld\n",ans);
	return 0;

}