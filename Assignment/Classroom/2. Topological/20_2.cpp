#include<bits/stdc++.h>
using namespace std;
vector<int>sorted;
vector<int> adj[10000];
vector<int> vertices;

void topologicalSort(int indegree[])
{
	queue<int> q;
    int i,flag[10000];
    memset(flag,0,10000);

    for(i=0;i<vertices.size();i++) 
    {
        int y=vertices[i];
    	if(indegree[y]==0 && flag[y]==0)
    	{
    		q.push(y);
    		flag[y]=1;
    	} 
    }

	while(!q.empty())
    {
        int u=q.front();
        sorted.push_back(u);
        q.pop();

        for(i=0;i<adj[u].size();i++)
        {
			int x=adj[u][i]; indegree[x]--;

            if(indegree[x]==0) q.push(x); 
        }
    }
}

void print()
{
	for(int i=0;i<sorted.size();i++) printf("%d ",sorted[i]);
	printf("\n");
}

int allpath(int s, int t)
{
	int w[10000];
	memset(w,0,10000);
    for(int i=sorted.size()-1;i>=0;i--)
    {
        int u=sorted[i];
        if(u==t) w[u]=1;
        else if(!adj[u].empty())
        {
            for(int j=0;j<=adj[u].size();j++)
            {
                int x=adj[u][j];
                w[u]=w[u]+w[x];
            }
            if(u==s) break;
        }
    }
    return w[s];
}

int main()
{
    int u,v,n,e,p,s,t;
    int indegree[10000];
    memset(indegree,0,10000);
    scanf("%d %d",&n,&e);

    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        vertices.push_back(u);  
        indegree[v]++;     
    }
    scanf("%d%d",&s,&t);

    topologicalSort(indegree);
    p=allpath(s,t);
    printf("%d\n",p);
    print();
    return 0;
}