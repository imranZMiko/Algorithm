/*
Given a directed acyclic graph (DAG) find a valid topological order.

Input
First line: N(0<N≤105), number of nodes. Second line: M(0<M≤3×105), number of edges. Next M lines, each: UV(0≤U,V<N), defines an edge from U to V.

Output
Output any valid topological order. See sample for clarification.

Sample
Input
-----
6
5
1 3
1 2
0 1
3 4
2 5

Output
------
0
1
2
5
3
4
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> sorted,adj[10000];
int indegree[10000],n,m;

void input()
{
    int i,u,v;
    memset(indegree,0,10000);
    scanf("%d %d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        indegree[v]++;     
    }

}

void topologicalSort()
{
	queue<int> q;
    int i,flag[10000];
    memset(flag,0,10000);

    for(i=0;i<n;i++) 
        if(indegree[i]==0 && flag[i]==0)
    	{
    		q.push(i);
    		flag[i]=1;
    	} 
    
    while(!q.empty())
    {
        int u=q.front();
        sorted.push_back(u);
        q.pop();

        for(int x:adj[u])
        {
			indegree[x]--;
            if(indegree[x]==0) q.push(x); 
        }
    }
}

void output()
{
	for(int i=0;i<sorted.size();i++) 
        printf("%d\n",sorted[i]);
}

int main()
{
    input();
    topologicalSort();
    output();
    return 0;
}