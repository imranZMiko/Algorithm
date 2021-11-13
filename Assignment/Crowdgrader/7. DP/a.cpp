/*
You are given two strings A and B. You need to find the longest common substring of A and B.

Input
First line: two strings A and B. Length of A, B will be between 1 and 100. A and B will only contain small English letters.

Output
The length of the longest common substring. See sample for clarification.

Sample
Input 1
-------
bangladesh
english

Output 1
--------
3

Input 2
-------
small
big

Output 2
--------
0
*/

#include<bits/stdc++.h>
using namespace std;

long long int dp[1005][1005],vi[1005][1005],x=0;
char a[1005],b[1005];

long long int f(long long int ia,long long int ib)
{
	if(ia==-1 || ib==-1) return 0;
	if(vi[ia][ib]) return dp[ia][ib];
	long long int ans=0,y=0,z=0;

	if(a[ia]==b[ib])
	{
		ans=f(ia-1,ib-1)+1;
		x=max(x,ans);
	}
	else ans=0;

	y=f(ia-1,ib);
	z=f(ia,ib-1);
		
	dp[ia][ib]=ans;
	vi[ia][ib]=1;
	return dp[ia][ib];
}

int main()
{
	long long int ans;
	scanf("%s%s",a,b);
	memset(vi,0,sizeof(vi));
	memset(dp,0,sizeof(dp));
	ans=f(strlen(a)-1,strlen(b)-1);
	printf("%lld\n",x);
	return 0;
}