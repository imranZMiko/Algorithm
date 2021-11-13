/*
Give an O(V, E)-time algorithm to compute the component graph of a directed graph G = (V, E). Your code should output each SCC with component no and the graph using component no as vertices. See the following input/ouput for clarification. Bonus: Make sure that there is at most one edge between two vertices in the component graph your algorithm produces.
*/

#include<bits/stdc++.h>
using namespace std;
int visited[10000],visited2[10000],numberofscc=0;
int sccval[10000],previous[10000],component_store[10000];
vector<int>component[10000];
vector<int> adj[10000];
vector<int> adjtrans[10000];
stack<int> sorted;
stack<int> storing;

void dfs_visit(int u)
{
    visited[u]=1;
    for(int v:adj[u]) 
        if (!visited[v]) dfs_visit(v);
    sorted.push(u);
}

void dfs() 
{
    while(!storing.empty()) 
    {
        int x=storing.top(); storing.pop();
        if(!visited[x]) dfs_visit(x);
    }
}

void dfs_visit2(int u) 
{
    visited2[u]=1;
    component[numberofscc].push_back(u);
    sccval[u]=numberofscc;
    for(int v:adjtrans[u]) 
        if(!visited2[v]) dfs_visit2(v);
}

void dfs2_scc() 
{
    while(!sorted.empty()) 
    {
        int x=sorted.top(); sorted.pop();
        if(!visited2[x]) 
        {
            numberofscc++;
            dfs_visit2(x);
        }
    }
}

void printscc()
{
    for(int i=0;i<numberofscc;i++)
    {
        printf("C%d: ",i+1);
        for(int j=0;j<component[i+1].size();j++)
        {
            if(j!=component[i+1].size()-1) printf("%d,",component[i+1][j]);
            else printf("%d\n",component[i+1][j]);
        }
    }
}

void printscc_graph()
{
    int count=0,j=0,i;
    for(i=1;i<=numberofscc;i++) 
        for(int u: component[i])
            for(int v: adj[u])
                if(sccval[u]!=sccval[v])
                    if(previous[sccval[v]]!=sccval[u])
                    {
                        previous[sccval[v]]=sccval[u];

                        component_store[j]=sccval[u];
                        component_store[j+1]=sccval[v];
                        count++; j=j+2;
                    }
    printf("Component Graph:\nNode = %d, Edge = %d\n",numberofscc,count);

    for(i=0;i<2*count;i=i+2) 
        printf("C%d C%d\n",component_store[i],component_store[i+1]);
} 

int main()
{
    int u,v,n,i,e;
    scanf("%d%d",&n,&e);

    for(i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adjtrans[v].push_back(u);
        storing.push(u);

    }

    dfs();
    dfs2_scc();
    printscc();
    printscc_graph();
    return 0;
}