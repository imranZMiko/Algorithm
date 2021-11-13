/*
How many positive decimal numbers of length N are there, where the difference between each consecutive digits are at most 2? For example, if N = 2, then the numbers are: 10, 11, 12, 13, 20, 21, 22, 23, 24, 31, 32, 33, 34, 35, 42, 43, 44, 45, 46, 53, 54, 55, 56, 57, 64, 65, 66, 67, 68, 75, 76, 77, 78, 79, 86, 87, 88, 89, 97, 98, 99.

Input
First line: N(0<N≤25), length of the number.

Output
Output the number of such numbers. See sample for clarification.

Sample
Input 1
-------
1

Output 1
--------
9

Input 2
-------
2

Output 2
--------
41

Input 3
-------
3

Output 3
--------
188

Input 4
-------
5

Output 4
--------
4010
*/

#include<bits/stdc++.h>
using namespace std;

long long int dp[110][110],arr[1000],vi[110][110],m;

long long int f(long long int n, int prev)
{
	if(n==0) return 1;

	if(vi[n][prev]) return dp[n][prev];
	
	long long int ans=0;

	for(int i=0;i<=9;i++)
	{
		if(prev!=100)
			if((i-prev)<=2 && (prev-i)<=2) 
				ans+=f(n-1,i);
		if(prev==100 && i!=0) ans+=f(n-1,i);
	}

	dp[n][prev]=ans;
	vi[n][prev]=1;
	return dp[n][prev];
}

int main()
{
	long long int ans,n;
	scanf("%lld",&n);
	ans = f(n,100);
	printf("%lld\n",ans);
	return 0;

}