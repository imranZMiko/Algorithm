/*
BFS(G, source, dest, dir){
    Q is an empty queue
    for each of the 4 directions{
        set the source.dir 
        Enqueue(Q, source);
        dis[source.x][source.y][source.dir] = 0;
        vi[source.x][source.y][source.dir] = 1;
    }
    while(Q not empty){
    u = Dequeue(Q);
        for each of the 4 directions{
            if(direction matches with new direction)
                v := new coordinates in current direction 
            else
                v := same coordinates in new direction
            if (v.x, v.y is within bounds and v not visited and is not blocked){
                vi[v.x][v.y][v.dir] = 1;
                dis[v.x][v.y][v.dir] = dis[u.x][u.y][u.dir]+ 1;
                Enqueue(Q, v);
            }
        }
    }
    return minimum of dis[dest.x][dest.y] among all directions
}
*/