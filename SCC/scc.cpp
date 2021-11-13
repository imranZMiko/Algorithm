/*
SCC(G)
	call DFS(G) to compute finishing times f [u] for all u
	compute GT
	call DFS(GT), but in the main loop, consider vertices in order of decreasing f [u] (as computed in first DFS)
	Each component found in this DFS are the SCCs.

Create an empty stack ‘S’ and do DFS traversal of a graph. 
In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack.
Reverse directions of all arcs to obtain the transpose graph.
One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v.

transpose (G) :
GT = {}
for u in G:
	for v in G[u]:
		GT[v].add(u)
return GT

DFS_Visit(S, v) :
	for each w adj[v]
		if(!visited[w])
			DFS_Visit(S, w)
			Push(S, w)

Stack S := empty
for each v G
	if(!visited[v])
		DFS_Visit(S, v)
		Push(S, v)
GT = transpose(G)
while(S is not empty)
	Stack Q := empty
	v = Pop(S)
	if(!visitedT[v])
		DFS_Visit(Q, v)
		Push(Q, v)
	while(Q is not empty)
		w = Pop(Q)
		print Q
*/