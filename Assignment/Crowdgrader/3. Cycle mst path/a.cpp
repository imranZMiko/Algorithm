/*
Given an directed weighted graph find if it has a negative cycle.

Input
First line: N(0<N≤100), number of nodes. Second line: M(0<M≤10000), number of edges. Next M lines, each: UVW(0≤U,V<N,−1000≤W≤1000), defines an edge from U to V with weight W.

Output
Output Yes/No. See sample for clarification

Sample 1
Input
-----
6
5
1 3 2
1 2 5
0 1 3
3 2 1
2 5 10

Output
------
No
Sample 2
Input
-----
6
5
1 3 2
2 1 -5
0 1 3
3 2 1
2 5 10

Output
------
Yes
*/

#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
struct edge
{
    int u,v;
    long long int w;
    edge();
    edge(int _u, int _v, long long int _w) 
    {
        u=_u; v=_v; w=_w;
    }
    
};

vector<edge> all_edges;
long long int d[100005];
int n,m;

void input()
{
    int u,v,i;
    long long int w;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d%d%lld",&u,&v,&w);
        all_edges.push_back(edge(u,v,w));
    }
}

void bellmanFord_output()
{
    int u,v,i,j;
    long long int w;
    
    for(i=0;i<n-1;i++) d[i]=INF;
    
    for(i=0;i<n-1;i++)
        for(j=0;j<m;j++)
            if(d[all_edges[j].v] > d[all_edges[j].u] + all_edges[j].w)
                d[all_edges[j].v] = d[all_edges[j].u] + all_edges[j].w;
           
    for(i=0;i<m;i++)
        if(d[all_edges[i].v] > d[all_edges[i].u] + all_edges[i].w)
        {
           printf("Yes\n"); return;
        } 
    printf("No\n");
}

int main()
{
    input();
    bellmanFord_output();
    return 0;
}