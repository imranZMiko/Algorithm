/*
BELLMAN-FORD(V, E, w, s)
	for each v ∈ V
		do d[v] := inf
	d[s] := 0
	for i ← 1 to |V| - 1
		do for each edge (u, v) ∈ E
			do d[v] > d[u] + w(u,v)
				then d[v] := d[u] + w(u,v)
	for each edge (u, v) ∈ E
		do if d[v] > d[u] + w(u, v)
		then return FALSE
	return TRUE
*/