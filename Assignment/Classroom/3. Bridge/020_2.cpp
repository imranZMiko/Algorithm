/*
Write a code to find the Articulation Points in a given undirected graph. Print all the APs as output.
*/

#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
#define NIL -1
vector<int> adjacent[10000];
vector<int> vertices;
int low[10000],previous_node[10000],color[10000];
int starting_time[10000],finishing_time[10000];
int time_,count_;

void dfs_visit(int v)
{
    int number_of_child=0;
    int flag=0;
	color[v]=GREY;
	time_++;
	starting_time[v]=time_;
	low[v]=starting_time[v];
	
	for(int w:adjacent[v])
	{

		if(color[w]==WHITE)
		{
            number_of_child++;
			previous_node[w]=v;
			dfs_visit(w);
            if(previous_node[v]==NIL && number_of_child>1)
			{
				if(!flag)
				{
					count_++;
					printf("Point %d: %d\n",count_,v);
					flag=1;
				}
			}
			if(previous_node[v]!=NIL && low[w]>=starting_time[v])
			{
				count_++;
				printf("Point %d: %d\n",count_,v);
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

void dfs_articulation()
{
	for(int i:vertices)
	{
		color[i]=0;
		previous_node[i]=NIL;
		low[i]=INT_MAX;
		starting_time[i]=INT_MAX;
		finishing_time[i]=INT_MAX;
	}
	time_ =0;
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
	dfs_articulation();
	return 0;
}