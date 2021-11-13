/*
You are given a 3xN sized grid which you need to fill up with tiles. You have 3 kinds of tiles of dimension 3x1, 3x2 and 3x3. You can rotate any tile if you want. In how many different ways you can tile the whole grid?

Input
First line: N(0<N≤50), size of the grid.

Output
Output the number of ways you can tile the grid. See sample for clarification.

Sample
Input 1
-------
2

Output 1
--------
2

Input 2
-------
3

Output 2
--------
7
*/

#include<bits/stdc++.h>
using namespace std;

long long int dp[110],vi[110];

long long int f(long long int n)
{
	if(n==0) return 1;
	if(n<0) return 0;

	if(vi[n]) return dp[n];

	long long int ans=0;

	ans=f(n-1)+f(n-2)+4*f(n-3);

	dp[n]=ans;
	vi[n]=1;
	return dp[n];
}

int main()
{
	long long int ans,n;
	scanf("%lld",&n);
	ans = f(n);
	printf("%lld\n",ans);
	
	return 0;

}