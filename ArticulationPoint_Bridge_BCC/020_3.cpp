#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
#define NIL -1
vector<int> adjacent[10000];
vector<int> vertices;
stack<pair <int, int>> edges;
int low[10000],previous_node[10000],color[10000];
int starting_time[10000],finishing_time[10000];
int time_,count_;

void printEdge(pair<int, int> node)
{
    printf("%d-%d ", node.first, node.second);
}

void dfs_visit(int v)
{
    int number_of_child=0;
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
            edges.push(make_pair(v,w));
			dfs_visit(w);
            if(previous_node[v]==NIL && number_of_child>1)
			{
				count_++;
				printf("BCC %d: ",count_);
                while(edges.top()!=make_pair(v,w))
                {
                    printEdge(edges.top());
                    edges.pop();
                }
                printEdge(edges.top());
                printf("\n");
                edges.pop();
			}
			if(previous_node[v]!=NIL && low[w]>=starting_time[v])
			{
				count_++;
				printf("BCC %d: ",count_);
                while(edges.top()!=make_pair(v,w))
                {
                    printEdge(edges.top());
                    edges.pop();
                }
                printEdge(edges.top());
                printf("\n");
                edges.pop();
			}
			if(low[w]<low[v])
				low[v]=low[w];
		}
		else if(previous_node[v]!=w)
		{
			if(starting_time[w]<low[v])
				low[v]=starting_time[w];
			if(starting_time[w]<starting_time[v])
				edges.push(make_pair(v,w));
		}
	}
	color[v]=BLACK;
	time_++;
	finishing_time[v]=time_;
}

void dfs_bcc()
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
        {
			dfs_visit(i);
            if(!edges.empty())
            {
                count_++;
                printf("BCC %d: ",count_);
            }
            while(!edges.empty())
            {
                printEdge(edges.top());
                edges.pop();
            }
            printf("\n");
        }
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
	dfs_bcc();
	return 0;
}