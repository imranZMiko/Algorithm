/*
A way to perform topological sorting on a directed acyclic graph G = (V, E) is to repeatedly find a vertex of in-degree 0, output it, and remove it and all of its outgoing edges from the graph. Explain how to implement this idea so that it runs in time O(V +E).
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>sorted;
vector<int> adj[10000];
vector<int> vertices;

void topologicalSort(int indegree[])
{
	queue<int> q;
    int i,flag[10000];
    memset(flag,0,10000);

    for(i=0;i<vertices.size();i++) 
    {
        int y=vertices[i];
    	if(indegree[y]==0 && flag[y]==0)
    	{
    		q.push(y);
    		flag[y]=1;
    	} 
    }

	while(!q.empty())
    {
        int u=q.front();
        sorted.push_back(u);
        q.pop();

        for(i=0;i<adj[u].size();i++)
        {
			int x=adj[u][i]; indegree[x]--;

            if(indegree[x]==0) q.push(x); 
        }
    }
}

void print()
{
	for(int i=0;i<sorted.size();i++) printf("%d ",sorted[i]);
	printf("\n");
}

int main()
{
    int u,v,n,i,e;
    int indegree[10000];
    memset(indegree,0,10000);
    scanf("%d %d",&n,&e);

    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        vertices.push_back(u);  
        indegree[v]++;     
    }
    
    topologicalSort(indegree);
    print();
    return 0;
}