/*
Given an undirected graph find all of its articulation points.

Input
First line: N(0<N≤105), number of nodes. Second line: M(0<M≤3×105), number of edges. Next M lines, each: UV(0≤U,V<N), defines an edge between U and V.

Output
Output the articulation points in a line in increasing order. See sample for clarification

Sample
Input
-----
6
6
1 3
1 2
2 3
0 1
3 4
5 0

Output
------
0
1
3
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> adjacent[10000],points;
int low[10000], previous_node[10000], visited[10000];
int starting_time[10000], time_,n,m;

void input()
{
	int i,u,v;
	scanf("%d%d", &n,&m);
	
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		adjacent[u].push_back(v); 
		adjacent[v].push_back(u);
		
	}

}
void dfs_visit(int v)
{
    int number_of_child=0,flag=0;
  	visited[v]=1;
	starting_time[v]=low[v]=time_++;
	
	
	for(int w:adjacent[v])
		if(!visited[w])
		{
            number_of_child++;
			previous_node[w]=v;
			dfs_visit(w);
            if(previous_node[v]==-1 && number_of_child>1)
				if(!flag)
				{
					points.push_back(v);
					flag=1;
				}
			if(previous_node[v]!=-1 && low[w]>=starting_time[v])
				points.push_back(v);
			low[v]=min(low[v],low[w]);
		}

		else if(previous_node[v]!=w)
			low[v]=min(starting_time[w],low[v]);

	time_++;
}

void dfs_articulation()
{
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
		previous_node[i]=-1;
		low[i]=INT_MAX;
		starting_time[i]=INT_MAX;
	}

	time_=0;

	for(int i=0;i<n;i++)
		if(!visited[i])
			dfs_visit(i);
	
}

void output()
{
	sort(points.begin(),points.end());
	for(int i:points)
		printf("%d\n",i);
	if(points.size()==0) printf("No articulation point\n");
	
}

int main()
{
	input();
	dfs_articulation();
	output();
	return 0;
}