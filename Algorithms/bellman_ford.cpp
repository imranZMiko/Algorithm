#include <bits/stdc++.h>

#define INF 1000000007
#define NIL -1
#define SIZE 100005

using namespace std;

long long int shortestPath[SIZE];
// bool visited[SIZE];

struct edge{
    int u, v, w;
    edge(){}
    edge(int _u, int _v, int _w){
        u = _u;
        v = _v;
        w = _w;
    }
};

vector<edge> edges;

void initialize(int n){
    for (int i = 0; i <= n; ++i)
    {
        shortestPath[i] = INF;
    }
}
 
void relax(edge e){
    int u, v, w;
    u = e.u;
    v = e.v;
    w = e.w;
    if(shortestPath[v] > shortestPath[u] + w){
        shortestPath[v] = shortestPath[u] + w;
    }
}

bool checkNegLoop(edge e){
    int u, v, w;
    u = e.u;
    v = e.v;
    w = e.w;

    if(shortestPath[v] > shortestPath[u] + w)
        return true;

    return false;
}

void inputEdges(int edgeCount){
    int u, v;
    long long int w;
    while(edgeCount--){
        scanf("%d %d %lld", &u, &v, &w);
        edges.push_back(edge(u,v,w));
    }
}

bool bellmanFord(int n, int m){
    int u, v, w;
    edge e;
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < m; ++j)
            relax(edges[j]);

    for (int i = 0; i < m; ++i)
        if( checkNegLoop(edges[i]) )
            return false;

    return true;
}

void output(bool loopDoesntExist){
    if(loopDoesntExist)
        printf("No\n");
    else
        printf("Yes\n");
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    initialize(n);

    inputEdges(m);

    output(bellmanFord(n, m));
    
    return 0;
}