/*
BFS(G, source, dest){
    Q is an empty queue
    Enqueue(Q, source);
    dis[source.x][source.y] = 0;
    vi[source.x][source.y] = 1;
    while(Q not empty){
    u = Dequeue(Q);
        for each of the 4 directions{
        	v := new coordinates
            if ((v.x, v.y) is within bounds and v not visited){
                vi[v.x][v.y] = 1;
                dis[v.x][v.y] = dis[u.x][u.y] + 1;
                Enqueue(Q, v);
            }
        }
    }
    return dis[dest.x][dest.y]
}
*/

#include <bits/stdc++.h>
using namespace std;

int dis[100][100], vi[100][100];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int sourcex, int sourcey, int destx, int desty){
	queue<int> q;
	int ux, uy, vx, vy;

	q.push(sourcex);
	q.push(sourcey);
	dis[sourcex][sourcey] = 0;
	vi[sourcex][sourcey] = 1;

	while(!q.empty()){
		ux = q.front(); q.pop();
		uy = q.front(); q.pop();
		
		for(int i = 0; i < 4; i++){
			vx = ux + dx[i];
			vy = uy + dy[i];

			if(vx >= 0 && vx < n && vy >= 0 && vy < n && !vi[vx][vy]){
				q.push(vx);
				q.push(vy);
				dis[vx][vy] = dis[ux][uy] + 1;
				vi[vx][vy] = 1;
			}
		}
	}
	return dis[destx][desty];
}

int main(){

}