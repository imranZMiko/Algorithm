#include<bits/stdc++.h>
using namespace std;
#define INF 10009
#define LOOP3 for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++)
#define LOOP2 for(i=0;i<n;i++) for(j=0;j<n;j++)
int dis[1000][1000],n,m;

void initialize()
{
	int i,j;
	memset(dis,0,sizeof(dis));
	for(i=0;i<n;i++) 
		for(j=0;j<n;j++) 
			if(i!=j) 
				dis[i][j]=INF;
			
}

void input()
{
	int u,v,w;
	scanf("%d%d",&n,&m);
	initialize();
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		if(dis[u][v]==INF)
		{
			
			dis[u][v]=w;
			dis[v][u]=w;
		}
		else if(dis[u][v]>w)
		{
			dis[u][v]=w;
			dis[v][u]=w;
		}
	}
	
}

void floyd_warshall()
{
	int i, j, k;
	for(k=0;k<n;k++) 
		for(i=0;i<n;i++) 
			for(j=0;j<n;j++) 
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
}
	
void printPath()
{
	int i,j;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
		{
			printf("%d to %d: ", i,j);
			if(dis[i][j]!=INF) printf("%d\n",dis[i][j]);
			else printf("No Path\n"); 
		}
}

int main()
{
	input();
	floyd_warshall();
	printPath();
	return 0;
}




