/*
EXTEND(L, W, n)
	create L’, an n × n matrix
	for i ← 1 to n
		do for j ← 1 to n
			do l'ij ←∞
	for k ← 1 to n
		do l'ij ← min(lij’, lik + wkj)
	return L’

SLOW-ALL-PAIRS-SHORTEST-PATHS(W, n)
	L(1) ← W
	for m ← 2 to n - 1
		do L(m) ←EXTEND (L(m - 1), W, n)
	return L(n - 1)
*/