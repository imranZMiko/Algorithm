#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int> adjacent[10000];
vector<int> vertices;
int low[10000],previous_node[10000],color[10000];
int starting_time[10000],finishing_time[10000];
int time_,count_;

void dfs_visit(int v)
{
	color[v]=GREY;
	time_++;
	starting_time[v]=time_;
	low[v]=starting_time[v];

	for(int w:adjacent[v])
	{
		if(color[w]==WHITE)
		{
			previous_node[w]=v;
			dfs_visit(w);
			if(low[w]>starting_time[v])
			{
				count_++;
				printf("Bridge %d: %d-%d\n",count_,v,w);
			}
			if(low[w]<low[v])
				low[v]=low[w];
		}
		else if(previous_node[v]!=w)
		{
			if(starting_time[w]<low[v])
				low[v]=starting_time[w];
		}
	}
	color[v]=BLACK;
	time_++;
	finishing_time[v]=time_;
}

void dfs_bridge()
{
	for(int i:vertices)
	{
		color[i]=WHITE;
		previous_node[i]=0;
		low[i]=INT_MAX;
		starting_time[i]=INT_MAX;
		finishing_time[i]=INT_MAX;
	}
	time_ = 0;
	count_=0;
	for(int i:vertices)
	{
		if(color[i]==WHITE)
			dfs_visit(i);
	}
}


int main()
{
	int i,node,edges,from,to;
	scanf("%d%d", &node,&edges);

	for(i=0;i<edges;i++)
	{
		scanf("%d%d",&from,&to);
		adjacent[from].push_back(to);
		adjacent[to].push_back(from);
		vertices.push_back(from);
		vertices.push_back(to);
	}
	dfs_bridge();
	return 0;
}