/*
Given an undirected graph find the minimum number of edges that you need add so that the graph doesn't contain any bridge.

Input
First line: N(0<N≤105), number of nodes. Second line: M(0<M≤3×105), number of edges. Next M lines, each: UV(0≤U,V<N), defines an edge between U and V.

Output
Minimum required edges. See sample for clarification

Sample
Input
-----
7
7
1 3
1 2
2 3
0 1
3 4
5 0
2 6
Output
------
2
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1000];
stack <int> s;
int starting_time[10000],low[10000],previous_node[10000];
int compID[10000],degree[10000],visited[10000];
int time_,count_,n,m;

void input()
{
    int i,u,v;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs_visit(int v)
{
    starting_time[v]=low[v]=time_++;
    visited[v]=1;
    s.push(v);
    
    for(int w:adj[v])
        if(!visited[w])
        {
            previous_node[w]=v;
            dfs_visit(w);
            low[v]=min(low[v],low[w]);
        }
        else if(previous_node[v]!=w)
            low[v]=min(starting_time[w],low[v]);
    
    time_++;

    if(low[v]==starting_time[v])
    {
        count_++;
        while(!s.empty())
        {
            int val=s.top();
            s.pop();
            compID[val]=count_;
            if(v==val) break;
        }
    }
}

void dfs_bridge()
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        previous_node[i]=-1;
        low[i]=INT_MAX;
        starting_time[i]=INT_MAX;
        degree[i]=0;
        
    }
    time_=0;
    count_=0;
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs_visit(i);
    
}

void output()
{
    while(!s.empty()) s.pop();
    dfs_bridge();
    int leaf=0;

    for(int i=0;i<n;i++)
        for(int v:adj[i])
            if(compID[i]!=compID[v])
            {                            
                degree[compID[i]]++;
                degree[compID[v]]++;
            }

    for(int i=1;i<=count_;i++)
        if(degree[i]==2) leaf++;

    printf("%d\n",(leaf+1)/2);
}

int main()
{  
    input(); 
    output();
    return 0;
}
