
#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
struct edge
{
    int u,v,w;
    edge();
    edge(int _u,int _v,int _w)
    {
        u=_u; v=_v; w=_w;
    }

    bool operator <(const edge &a)const
    {
        return w<a.w || (w==a.w && (v<a.v || u<a.u));
    }
};

vector<edge> all_edges;
vector<int> adjacent[10000];
bool is_part_of_MST[1000];
bool isbridge[1000][1000];
int parent[1000],counting=0,flag[1000],n,m;
int low[10000],previous_node[10000],color[10000];
int starting_time[10000],finishing_time[10000];
int time_;

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
                isbridge[v][w] = true;
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
    for(int i=0;i<n;i++)
    {
        color[i]=WHITE;
        previous_node[i]=0;
        low[i]=INT_MAX;
        starting_time[i]=INT_MAX;
        finishing_time[i]=INT_MAX;
    }
    time_ = 0;
    
    for(int i=0;i<n;i++)
    {
        if(color[i]==WHITE)
            dfs_visit(i);
    }
}




void input()
{
    int i,u,v,w;
    scanf("%d %d", &n, &m);
    
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d", &u,&v,&w);
        all_edges.push_back(edge(u,v,w));
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
        isbridge[u][v]=false;
        isbridge[v][u]=false;
    }
    sort(all_edges.begin(), all_edges.end());
}

int findRoot(int v)
{
    if(v==parent[v])
        return v;
    return findRoot(parent[v]);
}

void union_(int p,int q)
{
    int rootP, rootQ;
    rootP = findRoot(p);
    rootQ = findRoot(q);

    if(rootP != rootQ)
        parent[rootP] = rootQ;
}

int Kruskal()
{
    int p,q,cost=0,i;
    counting++;

    for (i=0;i<n;i++) parent[i]=i;
        
   
    if(counting==1)memset(is_part_of_MST,false,sizeof is_part_of_MST);
    
    for (i=0;i<m;i++)
    {
        p=all_edges[i].u;
        q=all_edges[i].v;

        if(findRoot(p)!=findRoot(q) && flag[i]==0)
        {
            
            union_(p, q);
            cost+=all_edges[i].w;
            if(counting==1)
                is_part_of_MST[i]=true;
        }
    }
    return cost;
}

int output()
{
    int i,store,lowest=INT_MAX,k;
    k=Kruskal();
   
    for (i=0;i<m;i++)
    {
        if(is_part_of_MST[i]==true && !isbridge[all_edges[i].u][all_edges[i].v])
        {
            flag[i]=1;
            store=Kruskal();
            flag[i]=0;
            if(store<lowest)
                lowest=store;
        }
    }
    if(lowest!=INT_MAX) printf("%d\n",lowest);
    else printf("No Second Best MST\n");
}

int main()
{
    input();
    dfs_bridge();
    output();
    return 0;
}