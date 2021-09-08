#include<bits/stdc++.h>
using namespace std;
#define LOOP3 for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) 
#define LOOP2 for(i=0;i<n;i++) for(j=0;j<n;j++)  
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
    LOOP3 
        path_count[i][j]+=path_count[i][k]*path_count[k][j];
}

void output()
{
    int i,j;
    floyd();
    LOOP2
        if(i!=j)
            printf("Number of paths from %d to %d: %llu\n", i, j, path_count[i][j]);
        
}

int main()
{
    input();
    output();
    return 0;
}