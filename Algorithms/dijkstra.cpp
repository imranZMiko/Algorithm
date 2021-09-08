#include<bits/stdc++.h>
using namespace std;

struct node {
	int v, w;
	node(){}
	node(int _v, int _w){
		v = _v;
		w = _w;
	}

	bool operator <(const node &a) const {
		return w > a.w || (w == a.w && v > a.v);
	}
};

vector<node> g[100];
int d[100] = {0};
int vi[100] = {0};

void dijkstra(int s){
	priority_queue<node> q;
	int u, v, w;

	d[s] = 0;
	vi[s] = 0;

	while(!q.empty()){
		u = q.top().v;
		q.pop();

		for(int i = 0; i < g[u].size(); i++){
			v = g[u][i].v;
			w = g[u][i].w;

			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				q.push(node(v, d[v]));
			}
		}
	}
}

void input(int m){
	int u, v, w;
	while(m--){
		scanf("%d %d %d", u, v, w);
		g[u].push_back(node(v,w));
	}
}