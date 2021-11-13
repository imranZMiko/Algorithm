/*
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
			do if d[v] > d[u] + w(u,v)
				then d[v] := d[u] + w(u,v)
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