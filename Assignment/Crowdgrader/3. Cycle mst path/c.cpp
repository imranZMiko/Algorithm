/*
Given a directed acyclic graph, find number of different paths between each pair of nodes in the graph.

Input
First line: N(0<N≤100), number of nodes. Second line: M(0<M≤1000), number of edges. Next M lines, each: UV(0≤U,V<N), defines an edge from U to V.

Output
Output a line for each pair of nodes U,V indicating number of paths from U to V. See sample for clarification.

Sample
Input
-----
3
4
0 1
0 2
2 1
0 2

Output
------
Number of paths from 0 to 1: 3
Number of paths from 0 to 2: 2
Number of paths from 1 to 0: 0
Number of paths from 1 to 2: 0
Number of paths from 2 to 0: 0
Number of paths from 2 to 1: 1
*/

#include<bits/stdc++.h>
using namespace std;

unsigned long long path_count[1000][1000];
int n,m;

void input()
{
    int u,v,i;
    scanf("%d%d",&n,&m);

    memset(path_count,0, sizeof path_count);

    for (i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        path_count[u][v]++;
    }
}

void floyd()
{
    int i,j,k;
    for(k=0;k<n;k++) 
        for(i=0;i<n;i++) 
            for(j=0;j<n;j++) 
                path_count[i][j]+=path_count[i][k]*path_count[k][j];
}

void output()
{
    int i,j;
    floyd();
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i!=j)
                printf("Number of paths from %d to %d: %llu\n", i, j, path_count[i][j]);
        
}

int main()
{
    input();
    output();
    return 0;
}