/*
BFS(G, source, dest){
    Q is an empty queue
    Enqueue(Q, source);
    dis[source] = 0;
    vi[source] = 1;
    while(Q not empty){
    u = Dequeue(Q);
        for each v ∈ adj[u]{
            if (v not visited){
                vi[v] = 1;
                dis[v] = dis[u] + 1;
                Enqueue(Q, v);
            }
        }
    }
    return dis[dest]
}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> g[100];
int dis[100], vi[100];

int bfs(int source, int dest){
	queue<int> q;
	int u, v;

	q.push(source);
	dis[source] = 0;
	vi[source] = 1;

	while(!q.empty()){
		u = q.front(); q.pop();

		for(int i = 0; i < g[u].size(); i++){
			v = g[u][i];
			if(!vi[v]){
				vi[v] = 1;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis[dest];
}

int main(){

}