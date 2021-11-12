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
            if ((v.x, v.y) is within bounds and v not visited and v is not blocked){
                vi[v.x][v.y] = 1;
                dis[v.x][v.y] = dis[u.x][u.y] + 1;
                Enqueue(Q, v);
            }
        }
    }
    return dis[dest.x][dest.y]
}
*/