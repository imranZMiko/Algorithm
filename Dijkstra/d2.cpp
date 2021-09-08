#include <bits/stdc++.h>
using namespace std;

struct node{
    int v, w;
    node(){}
    node(int _v, int _w){
        v = _v;
        w = _w;
    }

    bool operator <(const node &a)const{
        return w > a.w || (w == a.w && v > a.v);
    }
};

vector<node> adjacent[1000];
queue<int> stored;
int d[1000];

void output()
{
    while(stored.front()!=1)
    {
        printf("%d ",stored.front());
        stored.pop();
    }
    printf("\n");
}

void dijkstra(int s){
    priority_queue<node> q;
    int u, v, w, i, flag=0;

    d[s] = 0;
    

    q.push(node(s, d[s]));

    while(!q.empty()){
        u = q.top().v;
        q.pop();
        stored.push(u);
        if(u==1) flag=1;
        for(i = 0; i < adjacent[u].size(); i++){
            v = adjacent[u][i].v;
            w = adjacent[u][i].w;

            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                
                q.push(node(v,d[v]));
            }
        }
    }
    if(flag==0) printf("Not Reachable\n");
    else output();
}

void input(int m){
    int u, v, w;
    while(m--){
        scanf("%d %d %d", &u, &v, &w);
        adjacent[u].push_back(node(v,w));
        d[v] = INT_MAX;
        d[u] = INT_MAX;
        
    }
}

/*bool output(int d){
    if(d == 0){
        printf("0 ");
        return true;
    }
    if(previ[d] == NIL)
        return false;
    if(output(previ[d])){
        printf("%d ", d);
        return true;
    }
    else
        return false;
}*/

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    input(m);

    dijkstra(0);

    //output(1);
}


/*void printpath()
{
    vector<int> result;
    int u=n;
    while(u!=-1)
    {
        
        result.push_back(u);
        u=parent[u];
    }
    //if(result.size()==1 && result[0]==n)
    if(result[result.size()-1] != 1)
    {
            printf("-1\n");
            return;
    }

    //printf("1 ");

    while(!result.empty())
    {
        printf("%d ",result.back());
        result.pop_back();
    }
    printf("\n");
}*/

void printPath(long long int j)
{
    if(parent[j]==-1 && j==n){
        cout<<parent[j];
        return;
    }
    if (parent[j]==-1){
        cout<<j;
        return;
    }
 
    printPath(parent[j]);
 
    cout<<" "<<j;
}
 

void printPath()
{
   vector<int> path;
 
        for(int v = n; v != -1; v = parent[v]) path.push_back(v);
            if(path.size()==1 && path[0]==n) {
                cout<<"-1"<<endl;
                return;
            }
        for(int i = path.size()-1; i > 0; --i) cout<<path[i]<<" ";
 
       cout<<path[0]<<endl;
}


/*void printpath()
{
    vector<int> result;
    int u=n;
    while(u!=-1)
    {
        
        result.push_back(u);
        u=parent[u];
    }
    //if(result.size()==1 && result[0]==n)
   
    if(result[result.size()-1] != 1)
    {
            printf("-1\n");
            return;
    }
  
    //printf("1 ");

    /*while(!result.empty())
    {
        printf("%d ",result.back());
        result.pop_back();
    }
    printf("\n");

    for(int i=result.size()-1;i>0;i--)  printf("%d ",result[i]);
     printf("%d\n",result[0]);

}*/