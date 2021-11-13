/*
Floyd-Warshall(W[1..n][1..n])
D ← W
for k ← 1 to n do
	for i ← 1 to n do
		for j ← 1 to n do
			D[i][j] ← max(D[i][j], min(D[i][k], D[k][j]))
return D

Dijkstra(G,w,s)
	for each v ∈ V
		do d[v] := inf
	d[s] := 0
	S := empty set
	Q := V
	while Q != empty set
		do u := extract_min(Q)
		S := S U {u}
		for each v ∈ Adj[u]
			do if d[v] < d[u] + w(u,v)
				then d[v] := d[u] + w(u,v)
*/