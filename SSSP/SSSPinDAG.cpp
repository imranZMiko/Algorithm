/*
DAG-SHORTEST-PATHS(G,w, s)
	topologically sort the vertices of G
	for each v ∈ V
		do d[v] := inf
	d[s] := 0
	for each vertex u, taken in topologically sorted order
		do for each vertex v ∈ Adj[u]
			do d[v] > d[u] + w(u,v)
				then d[v] := d[u] + w(u,v)
*/