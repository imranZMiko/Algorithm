/*
DFS(G)
{
	for each vertex u ∈ V {
		color[u] = WHITE;
		prev[u]=NIL;
		low[u]=inf;
		f[u]=inf; d[u]=inf;
	}
	time = 0;
	for each vertex u ∈ V
		if (color[u] == WHITE)
			DFS_Visit(u);
}

DFS_Visit(v){
	color[v]=GREY;time=time+1;d[v] = time;
	low[v]= d[v];

	for each w ∈ Adj[v]{
		if(color[w] == WHITE){
			prev[w]=u;
			DFS_Visit(w);
			if low[w] >= d[v]
				record that vertex v is an articulation
			if (low[w] < low[v]) 
				low[v] := low[w];
		}
		else if w is not the parent of v then
			if (d[w] < low[v]) low[v] := d[w];
	}
	color[v] = BLACK; time = time+1; f[v] = time;
}
*/