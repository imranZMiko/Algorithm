#include<bits/stdc++.h>
using namespace std;
static const int mod = 1e9;

long long int dp[1000009], vi[1000009];

long long int f(long long int n)
{
	if(n==1) return 1;

	if(vi[n]) return dp[n];
	long long int ans=0;

	if(n%2!=0) ans=f(n-1);
	else ans=(f(n-1)+f(n/2))%mod;

	dp[n]=ans;
	vi[n]=1;
	return dp[n];
}

int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",f(n));
    }
    return 0;
}