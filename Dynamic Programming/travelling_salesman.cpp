#define inf 1e5
int d[100][100], w[100][100], n, vi[100], ans;

void solve_tsp(int u, int sum, int cnt){
	if(sum >= ans) return;

	if(sum + w[u][0] >= ans) return;

	if(cnt == n){
		if(d[u][0] < inf && ans > sum) ans = sum;
		return;
	}
	int v, tmp, ret = 0;
	for(v = 0; v < n; v++){
		if(!vi[v]){
			vi[v] = 1;
			solve_tsp(v, sum + d[u][v], cnt+1);
			vi[v] = 0;
		}
	}
}