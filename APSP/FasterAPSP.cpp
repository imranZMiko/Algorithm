/*
EXTEND(L, W, n)
	create L’, an n × n matrix
	for i ← 1 to n
		do for j ← 1 to n
			do l'ij ←∞
	for k ← 1 to n
		do l'ij ← min(lij’, lik + wkj)
	return L’

FASTER-APSP(W, n)
	L(1) ← W
	m ← 1
	while m < n - 1
	do L(2m) ← EXTEND(L(m), L(m), n)
		m ← 2*m
	return L(m)
*/