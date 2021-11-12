/*
You are given a 2D grid. From each cell you can move to 4 directions (left, right, up, down). Each cell in the grid has a color (R, G or B). You are not allowed to step into the same colored cell consecutively. You have to find the shortest path from (0, 0) to (N-1, M-1) where N is the number of rows and M is the number of columns in the grid. The input will contain N and M characters containing R, G or B, which indicates the color of the corresponding cell in the grid. Any valid shortest path will do.
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y;
};

int dis[100][100], vi[100][100];
node previ[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(node source, node dest, char mat[][1000], int n, int m){
	queue<node> q;
	node u, v;

	memset(dis, 0, sizeof(dis));
	memset(vi, 0, sizeof(vi));
	memset(previ, 0, sizeof(previ));
	
	q.push(source);
	dis[source.x][source.y] = 0;
	vi[source.x][source.y] = 1;   

	while(!q.empty()){
		u = q.front(); q.pop();

		for(int i = 0; i < 4; i++){
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];

			if(v.x >= 0 && v.x < n && v.y >= 0 && v.y < m && mat[v.x][v.y] != mat[u.x][u.y] && !vi[v.x][v.y]){
				q.push(v);
				dis[v.x][v.y] = dis[u.x][u.y] + 1;
				vi[v.x][v.y] = 1;
				previ[v.x][v.y] = u;
			}
		}
	}

	return dis[dest.x][dest.y];
}

void printPath(node start, node n){
    if(previ[n.x][n.y].x == 0 && previ[n.x][n.y].y == 0 && !(n.x==1 && n.y == 0) && !(n.x==0 && n.y == 1) && !(n.x==0 && n.y == 0)){
        printf("Path does not exist");  
    }
	else if(n.x == start.x && n.y== start.y)
		printf("Shortest path = (%d, %d) ", start.x, start.y);
	else{
		printPath(start, previ[n.x][n.y]);
		printf("-> (%d, %d) ", n.x, n.y);
	}
}

int main(){
	char matrix[1000][1000];
	int n, m, length;
	node start, end;

	scanf("%d %d", &n, &m);
	start.x = 0; start.y = 0;
	end.x = n-1; end.y = m-1;

	getchar();
	for(int i = 0; i < n; i++){
		fgets(matrix[i], 1000, stdin);
	}

	length = bfs(start, end, matrix, n, m);

	printf("Shortest path length = %d\n", length);

	printPath(start, end);
	printf("\n");

	return 0;
}