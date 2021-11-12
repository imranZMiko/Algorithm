/*
BFS(G, source, dest, dir, t){
    Q is an empty queue
    for each of the 4 directions{
        set the source.dir 
        set source.t to 0
        Enqueue(Q, source);
        dis[source.x][source.y][source.dir][source.t] = 0;
        vi[source.x][source.y][source.dir][source.t] = 1;
    }
    while(Q not empty){
        u = Dequeue(Q);
        for each of the 4 directions{
            if(direction == new direction)
                v := new coordinates in current direction with new time parity
            else
                v := same coordinates in new direction with new time parity
            if (v.x, v.y is within bounds and v not visited and is not blocked){
                vi[v.x][v.y][v.dir][v.t] = 1;
                dis[v.x][v.y][v.dir][v.t] = dis[u.x][u.y][u.dir][u.t] + 1;
                Enqueue(Q, v);
            }
            else if (v.x, v.y is within bounds and v not visited and is blocked){
                if(t is even){
                    vi[v.x][v.y][v.dir][v.t] = 1;
                    dis[v.x][v.y][v.dir][v.t] = dis[u.x][u.y][u.dir][u.t] + 1;
                    Enqueue(Q, v);
                }
                else {
                    v := same coordinates in same direction with new time parity
                    vi[v.x][v.y][v.dir][v.t] = 1;
                    dis[v.x][v.y][v.dir][v.t] = dis[u.x][u.y][u.dir][u.t] + 1;
                    Enqueue(Q, v);
                }
            }
        }
    }
    return minimum of dis[dest.x][dest.y] among all directions and between the time parities
}
*/