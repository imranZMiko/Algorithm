/*
Given an undirected weighted graph print the shortest path of node 1 from the node 0. If there are multiple shortest paths, print any one of them.

Input
First line: N(0<N≤100000), number of nodes.

Second line: M(0<M≤300000), number of edges.

Next M lines, each: UVW(0≤U,V<N,0<W<109), defines an edge between U and V with weight W.

Output
Shortest path of node 1. If node 1 is not reachable, print “Not Reachable”. See sample for clarification

Sample Input
7
6
4 3 2
4 2 5
0 4 3
3 2 1 
3 6 50 
2 1 10 
Sample Output
0 4 3 2 1
*/

#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v;
	long long int w;
	node(){}
	node(int _v, long long int _w)
	{
		v=_v;
		w=_w;
	}
	bool operator <(const node &a)const
	{
		return w>a.w || (w==a.w && v<a.v);
	}
};

vector<node> adjacent[300005];
int parent[300005],n,m;
long long int d[300005];

void input()
{
	int u,v;
	long long int w;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%lld",&u,&v,&w);
		adjacent[u].push_back(node(v,w));
		adjacent[v].push_back(node(u,w));
	}
	
}

void dijkstra(int s)
{
	priority_queue<node> q;
	for (int i=1;i<=n;i++)
	{
		d[i]=INT_MAX; 
		parent[i]=-1;
	}
	d[s]=0;
    q.push(node(s,d[s]));
    
	while(!q.empty())
	{
		int u=q.top().v;
		q.pop();

		for(int i=0;i<adjacent[u].size();i++)
		{
			int v=adjacent[u][i].v;
			int w=adjacent[u][i].w;
			if(d[v]==INT_MAX || (d[v]>d[u]+w))
			{
				d[v]=d[u]+w;
				q.push(node(v,d[v]));
				parent[v]=u;
			}
		}
	}
}

void printpath()
{
	stack<int> result;
	int u=1;
	while(u!=0)
	{
		if(parent[u]==-1)
		{
			printf("-1\n");
			return;
		}
		result.push(u);
		u=parent[u];
	}
 
	printf("0 ");
 	while(!result.empty())
	{
		printf("%d ",result.top());
		result.pop();
	}
	printf("\n");
}


int main()
{
	input();
	dijkstra(0);
	printpath();
	return 0;
}