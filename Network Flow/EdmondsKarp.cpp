/*
Ford-Fulkerson(G,s,t)
	for each edge (u,v)∈G.E do
		f(u,v) = f(v,u) = 0
	while ∃ path p from s to t in residual network Gf do (FIND PATH USING BFS)
		cf = min{cf(u,v): (u,v)∈p}
		for each edge (u,v) in p do
			f(u,v) = f(u,v) + cf
			f(v,u) = -f(u,v)
	return f
*/