/*
Given an undirected weighted graph find its all pair shortest path cost. The graph can have multi-edge.

Input
First line: N(0<N≤100), number of nodes.

Second line: M(0<M≤10000), number of edges.

Next M lines, each: UVW(0≤U,V<N,0<W≤1000), defines an edge between U and V with weight W.

Output
All Pair shortest path in increasing order of nodes. If there is no path, print “No Path”. See sample for clarification.

Sample Input
6  
5
1 3 2
1 2 5
0 1 3
3 2 1
2 5 10
Sample Output
0 to 1: 3
0 to 2: 6
0 to 3: 5
0 to 4: No Path
0 to 5: 16
1 to 2: 3
1 to 3: 2
1 to 4: No Path
1 to 5: 13
2 to 3: 1
2 to 4: No Path
2 to 5: 10
3 to 4: No Path
3 to 5: 11
4 to 5: No Path
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 10009
#define LOOP3 for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++)
#define LOOP2 for(i=0;i<n;i++) for(j=0;j<n;j++)
int dis[1000][1000],n,m;

void initialize()
{
	int i,j;
	memset(dis,0,sizeof(dis));
	LOOP2 if(i!=j) dis[i][j]=INF;
			
}

void input()
{
	int u,v,w;
	scanf("%d%d",&n,&m);
	initialize();
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		if(dis[u][v]==INF)
		{
			
			dis[u][v]=w;
			dis[v][u]=w;
		}
		else if(dis[u][v]>w)
		{
			dis[u][v]=w;
			dis[v][u]=w;
		}
	}
	
}

void floyd_warshall()
{
	int i, j, k;
	LOOP3 if(dis[i][k]+dis[k][j]<dis[i][j])
			dis[i][j]=dis[i][k]+dis[k][j];
}
	
void printPath()
{
	int i,j;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
		{
			printf("%d to %d: ", i,j);
			if(dis[i][j]!=INF) printf("%d\n",dis[i][j]);
			else printf("No Path\n"); 
		}
}

int main()
{
	input();
	floyd_warshall();
	printPath();
	return 0;
}




