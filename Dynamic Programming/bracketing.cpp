/*
//Find number of ways to make a valid n-length sequence of brackets

bracket(n){
	if(n == 0){
		dp[n] = 1;
		return dp[n];
	}

	for(j = 1; j < n; j+=2){
		a = bracket(j-1)
		b = bracket(n-1-j)
		dp[n] = a*b
	}

	return dp[n]
}

//Maximize the result of an arithmetic expression by using brackets
//Assuming single digit operands in a string input

f(st, end){
	if(st == end) return s[st] - '0';
	ans = 0
	for(j = st + 2; j < end; j+=2){
		a = f(st, j)
		b = f(j+2, end)
		if(st[j+1] == '*')
			tmp = a*b
		else
			tmp = a+b
		ans = max(ans, tmp)
	}
}

//Minimize the number of multiplications done to multiply a chain of matrices
f(st, end){
	if(st == end) 0;
	ans = 0
	for(j = st; j < end; j+=2){
		a = f(st, j)
		b = f(j+1, end)
		c = A[st] * A[j+1] * A[end+1]
		ans = max(ans, (a+b+c))
	}
}
*/